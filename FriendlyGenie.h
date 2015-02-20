#ifndef __ARABIANNIGHTS_FRIENDLYGENIE_H__
#define __ARABIANNIGHTS_FRIENDLYGENIE_H__
 
#include <iostream>
#include "Genie.h"
 
namespace arabiannights {
 
  /**
   * A friendly genie is actually a normal genie, but with special
   * descriptive text.
   */
  class FriendlyGenie : public Genie {
 
  public:
    /**
     * @param limit the maximum number of wishes to grant.
     */
    FriendlyGenie(int limit) : Genie(limit) {}
 
    /**
     * Redefined from Genie.
     * @return the number of wishes left to grant.
     */
    inline int nRemainingWishes() const {
      return getLimit() - nGrantedWishes();
    }
 
    /**
     * Dump to output stream.
     * @param o the output stream.
     */
    void dumpTo(std::ostream &o) const {
      o << "Friendly genie has granted " << nGrantedWishes()
        << " wishes and still has " << nRemainingWishes() << " to grant.";
    }
 
    /**
     * Output operator.
     * Declared friend: see alternative below (after class).
     */
    friend std::ostream &operator<<(std::ostream &o, const FriendlyGenie &fg) {
      fg.dumpTo(o);
      return o;
    }
 
  };
 
} // namespace arabiannights
 
#if 0
// alternative definition for output operator (non-friend)
inline std::ostream &operator<<(std::ostream &o, const FriendlyGenie &fg) {
  fg.dumpTo(o);
  return o;
}
#endif
 
#endif
