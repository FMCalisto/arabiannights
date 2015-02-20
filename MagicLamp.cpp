#include "MagicLamp.h"
 
  arabiannights::MagicLamp::~MagicLamp() {
    if (_demon) delete _demon;
    for (size_t gx = 0; gx < _genies.size(); gx++)
      delete _genies[gx];
  }
 
  /**
   * Ask the lamp for a genie.
   * If the number of rubs is even, return a grumpy genie.
   * If the number of rubs is more than the limit, return a demon.
   * Otherwise, return a normal friendly genie.
   * @return a genie.
   */
  arabiannights::Genie *arabiannights::MagicLamp::rub(int wishes) {
    Genie *g;
    if (_rubs < _limit) {
      _rubs++;
      _totalRubs++;
      if (_totalRubs % 2 == 0) {
        g = new FriendlyGenie(wishes);
        _genies.push_back(g);  // remember we created the genie
        return g;              // return genie to the caller
      }
      Genie *g = new GrumpyGenie(wishes);
      _genies.push_back(g);    // remember we created the genie
      return g;                // return genie to the caller
    }
    return _demon = (_demon ? _demon : new RecyclableDemon(wishes));
  }
 
  /**
   * Recharge the magic lamp by feeding it a demon.
   * A demon can only be used if not previously recycled.
   * Note that previously create genies ARE NOT deleted
   * (they may still be active).
   * @param demon the recyclable demon.
   */
  void arabiannights::MagicLamp::feedDemon(arabiannights::RecyclableDemon *demon) {
    if (demon != _demon) return; // only accept our demon...
    if (!demon->recycled()) {
      demon->recycle();
      delete _demon;  // zap the lamp's demon and reset lamp
      _demon = NULL;
      _rubs = 0;
      _demons++;
    }
  }
