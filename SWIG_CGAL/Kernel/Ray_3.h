#ifndef SWIG_CGAL_KERNEL_RAY_3_H
#define SWIG_CGAL_KERNEL_RAY_3_H

#include <sstream>
#include <SWIG_CGAL/Kernel/include_conflicts_3.h>
#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Kernel/Point_3.h>
#include <SWIG_CGAL/Kernel/Vector_3.h>
#include <SWIG_CGAL/Kernel/Line_3.h>
#include <SWIG_CGAL/Kernel/Direction_3.h>


class SWIG_CGAL_KERNEL_DECL Ray_3{
  EPIC_Kernel::Ray_3 data;
public:
  #ifndef SWIG
  typedef EPIC_Kernel::Ray_3 cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  Ray_3(const cpp_base& base):data(base){}
  #endif

//Creation
  Ray_3(const Point_3& p,const Point_3& q):data(p.get_data(),q.get_data()){}
  inline Ray_3(const Point_3& p,const Direction_3& d);
  inline Ray_3(const Point_3& p,const Vector_3& v);
  inline Ray_3(const Point_3& p,const Line_3& l);
//Operations
  SWIG_CGAL_FORWARD_CALL_AND_REF_0(Point_3,source)
  SWIG_CGAL_FORWARD_CALL_AND_REF_1(Point_3,point,int)
  SWIG_CGAL_DECLARE_CALL_AND_REF_0(Direction_3,direction)
  SWIG_CGAL_DECLARE_CALL_AND_REF_0(Vector_3,to_vector)
  SWIG_CGAL_DECLARE_CALL_AND_REF_0(Line_3,supporting_line)
  SWIG_CGAL_DECLARE_CALL_AND_REF_0(Ray_3,opposite)
  SWIG_CGAL_FORWARD_CALL_0(bool,is_degenerate)
  SWIG_CGAL_FORWARD_CALL_1(bool,has_on,Point_3)
//equality functors
  bool equals(const Ray_3& r){return data==r.get_data();}
  #ifdef NO_SWIG_OR_PYTHON
  bool __ne__(const Ray_3& r){return data!=r.get_data();}
  #endif
//I/O
  std::string toString(){
    std::stringstream sstr;
    sstr << data;
    return sstr.str();
  }
};

#endif //SWIG_CGAL_KERNEL_RAY_3_H
//  Ray_3<Kernel> r.transform ( Aff_transformation_3<Kernel> t)
