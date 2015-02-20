#ifndef __ARABIANNIGHTS_MAGICLAMP_H__
  #define __ARABIANNIGHTS_MAGICLAMP_H__
 
  #include <vector>
 
  #include "Genie.h"
  #include "FriendlyGenie.h"
  #include "GrumpyGenie.h"
  #include "RecyclableDemon.h"
 
  namespace arabiannights {
 
    class Genie;             // just a declaration
    class RecyclableDemon;   // just a declaration
 
    class MagicLamp {
 
      /** Maximum number of geneies in the lamp. */
      int _limit;
 
      /** Total number of rubs. */
      int _totalRubs;
 
      /** Number of rubs since last charge. */
      int _rubs;
 
      /** Number of recharges. */
      int _demons;
 
      /** Keep track of genies. */
      std::vector<Genie*> _genies;
 
      /** Keep track of demon. */
      RecyclableDemon *_demon;
 
    public:
      MagicLamp(int limit)
        : _limit(limit), _totalRubs(0), _rubs(0), _demons(0), _demon(NULL) {}
 
      /**
       * Destructor should be virtual (we have other virtual functions), even
       * though we do not have any subclasses of MagicLamp.
       */
      virtual ~MagicLamp();
 
      int getLimit()     const { return _limit; }
      int getRubs()      const { return _rubs; }
      int getTotalRubs() const { return _totalRubs; }
 
      int  nGenies() const { return getLimit() - getRubs(); }
      int  nDemons() const { return _demons; }
 
      /**
       * Ask the lamp for a genie.
       * If the number of rubs is even, return a grumpy genie.
       * If the number of rubs is more than the limit, return a demon.
       * Otherwise, return a normal friendly genie.
       * @return a genie.
       */
      virtual Genie *rub(int wishes);
 
      /**
       * Recharge the magic lamp by feeding it a demon.
       * A demon can only be used if not previously recycled.
       * @param demon the recyclable demon.
       */
      virtual void feedDemon(RecyclableDemon *demon);
 
      /**
       * Compare this lamp with another.
       * @return true if, in addition to the same capacity, the number
       * of available genies and the number of recharges are the same;
       * false, otherwise.
       */
      inline bool operator==(const MagicLamp &l) {
        return getLimit() == l.getLimit() &&
               nGenies()  == l.nGenies() && nDemons() == l.nDemons();
      }
 
    };
 
  } // namespace arabiannights
 
  #endif
