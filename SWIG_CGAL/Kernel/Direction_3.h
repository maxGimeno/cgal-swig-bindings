#ifndef SWIG_CGAL_KERNEL_DIRECTION_3_H
#define SWIG_CGAL_KERNEL_DIRECTION_3_H

#include <sstream>
#include <SWIG_CGAL/Kernel/include_conflicts_3.h>
#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Kernel/Segment_3.h>
#include <SWIG_CGAL/Kernel/Line_3.h>
#include <SWIG_CGAL/Kernel/Ray_3.h>
#include <SWIG_CGAL/Kernel/Vector_3.h>


class SWIG_CGAL_KERNEL_DECL Direction_3{
  EPIC_Kernel::Direction_3 data;
public:
  #ifndef SWIG
  typedef EPIC_Kernel::Direction_3 cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  Direction_3(const cpp_base& base):data(base){}
  #endif

//Creation
  Direction_3(double x, double y, double z):data(x,y,z){}
  inline Direction_3(const Vector_3& v);
  inline Direction_3(const Line_3& l);
  inline Direction_3(const Ray_3& r);
  inline Direction_3(const Segment_3& s);
//Operations
  SWIG_CGAL_FORWARD_CALL_1(double,delta,int)
  SWIG_CGAL_FORWARD_CALL_0(double,dx)
  SWIG_CGAL_FORWARD_CALL_0(double,dy)
  SWIG_CGAL_FORWARD_CALL_0(double,dz)
  SWIG_CGAL_DECLARE_CALL_AND_REF_0(Vector_3,vector)
//equality functors
  bool equals(const Direction_3& r){return data==r.get_data();}
  #ifdef NO_SWIG_OR_PYTHON
  bool __ne__(const Direction_3& r){return data!=r.get_data();}
  #endif
//I/O
  std::string   toString(){
    std::stringstream sstr;
    sstr << data;
    return sstr.str();
  }
};  

#endif //SWIG_CGAL_KERNEL_DIRECTION_3_H

//Direction_3<Kernel> d.operator- () The direction opposite to d.
//Direction_3<Kernel> d.transform ( Aff_transformation_3<Kernel> t)
