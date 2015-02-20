#ifndef __ARABIANNIGHTS_GENIE_H__
#define __ARABIANNIGHTS_GENIE_H__
 
#include <iostream>
 
namespace arabiannights {
 
  class Genie {
 
    /** Maximum number of wishes (does not mean that the genie will grant them all). */
    int _limit;
 
    /** Number of wishes granted. */
    int _granted;
 
  protected:
    // only instances from superclasses are allowed
    Genie(int limit) : _limit(limit), _granted(0) {}
 
  public:
    virtual ~Genie() {}
 
  public:
    int getLimit() const { return _limit; }
 
  public:
    virtual int  nGrantedWishes()   const { return _granted; }
    virtual void incrementGranted()       { _granted++; }
 
    /**
     * Ask the genie to grant a wish.
     * Never allow more grants than the initial limit.
     * @return true if the wish is granted; false otherwise.
     */
    virtual bool grantWish() {
      if (canGrantWish()) {
        incrementGranted();
        doGrantWish();
        return true;
      }
      return false;
    }
 
    /**
     * Decide if genie can grant a wish.
     * @return true or false (depends on special circumstances).
     */
    virtual bool canGrantWish() const { return _granted < _limit; }
 
    /**
     * Do actual wish granting. By default, does not do anything.
     */
    virtual void doGrantWish() {}
 
    /**
     * Template method: how to dump to an output stream?
     * @param o the output stream.
     * @note pure virtual.
     */
    virtual void dumpTo(std::ostream &o) const = 0;
 
    /**
     * Output operator.
     * Declared friend: see alternative below (after class).
     */
    friend std::ostream &operator<<(std::ostream &o, const Genie &g) {
      g.dumpTo(o);
      return o;
    }
 
 
  };
 
} // namespace arabiannights
 
#if 0
inline std::ostream &operator<<(std::ostream &o, const Genie &g) {
  rd.dumpTo(o);
  return o;
}
#endif
 
#endif
