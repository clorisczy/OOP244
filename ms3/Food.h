#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"

namespace seneca {

   class Food : public Billable {
      bool m_ordered{};
      bool m_child{};
      char* m_customize{};

   public:
      Food();
      Food(const Food& F);
      Food& operator=(const Food& F);
      ~Food();

      std::ostream& print(std::ostream& ostr = std::cout) const;
      bool order();
      bool ordered() const;
      std::ifstream& read(std::ifstream& file);
      double price() const;
   };

}

#endif