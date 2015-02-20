#ifndef __ARABIANNIGHTS_GRUMPYGENIE_H__
#define __ARABIANNIGHTS_GRUMPYGENIE_H__
 
#include <iostream>
#include "Genie.h"
 
namespace arabiannights {
 
  /**
   * This is actually a normal Genie with only one wish.
   */
  class GrumpyGenie : public Genie {
 
  public:
    /**
     * @param limit the number of wishes to grant (ignored: always grants only one wish).
     */
    GrumpyGenie(int limit) : Genie(1) {}
 
    /**
     * Dump to output stream.
     * @param o the output stream.
     */
    void dumpTo(std::ostream &o) const {
      o << ((nGrantedWishes() == 1) ? "Grumpy genie has granted a wish." : "Grumpy genie has a wish to grant.");
    }
 
    /**
     * Output operator.
     * Declared friend: see alternative below (after class).
     */
    friend std::ostream &operator<<(std::ostream &o, const GrumpyGenie &gg) {
      gg.dumpTo(o);
      return o;
    }
 
  };
 
} // namespace arabiannights
 
#if 0
inline std::ostream &operator<<(std::ostream &o, const GrumpyGenie &gg) {
  gg.dumpTo(o);
  return o;
}
#endif
 
#endif
