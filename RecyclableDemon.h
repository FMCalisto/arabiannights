#ifndef __ARABIANNIGHTS_RECYCLABLEDEMON_H__
#define __ARABIANNIGHTS_RECYCLABLEDEMON_H__
 
#include <iostream>
#include "Genie.h"
 
namespace arabiannights {
 
  class RecyclableDemon : public Genie {
    /** Has it been recycled? */
    bool _recycled;
 
    /**
     * Recycle a demon (called by a magic lantern).
     * @note this method is private to avoid it being called by anyone other than a magic lamp.
     */
    friend class MagicLamp;  // for calling recycle
    void recycle() { _recycled = true; }
 
  public:
 
    /**
     * @param wishes the number of wishes to grant (ignored: always grants wishes).
     */
    RecyclableDemon(int limit) : Genie(limit), _recycled(false) {}
 
    /**
     * Recyclable demons always grant wishes (unless it has been recycled).
     * @return true if not yet recycled; false, otherwise.
     */
    bool canGrantWish() const { return !_recycled; }
 
    /**
     * @return whether a demon has been recycled.
     */
    bool recycled() const { return _recycled; }
 
    /**
     * Dump to output stream.
     */
    void dumpTo(std::ostream &o) const {
      if (_recycled) o << "Demon has been recycled.";
      else           o << "Recyclable demon has granted " << nGrantedWishes() << " wishes.";
    }
 
    /**
     * Output operator.
     * Declared friend: see alternative below (after class).
     */
    friend std::ostream &operator<<(std::ostream &o, const RecyclableDemon &rd) {
      rd.dumpTo(o);
      return o;
    }
 
  };
 
} // namespace arabiannights
 
#if 0
inline std::ostream &operator<<(std::ostream &o, const RecyclableDemon &rd) {
  rd.dumpTo(o);
  return o;
}
#endif
 
#endif
