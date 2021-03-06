// ------------------------------------------------------------------------------
// Copyright (c) 2011 GeometryFactory (FRANCE)
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
// ------------------------------------------------------------------------------ 


#ifndef SWIG_CGAL_KERNEL_WEIGHTED_POINT_3_H
#define SWIG_CGAL_KERNEL_WEIGHTED_POINT_3_H

#include <sstream>
#include <SWIG_CGAL/Kernel/typedefs.h>
#include <SWIG_CGAL/Kernel/Point_3.h>
#include <CGAL/Weighted_point_3.h>

class SWIG_CGAL_KERNEL_DECL Weighted_point_3{
public:
  typedef CGAL::Weighted_point_3<EPIC_Kernel> cpp_base;
private:
  cpp_base data;
public:
  #ifndef SWIG
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  Weighted_point_3(const cpp_base& base):data(base){}
  #endif

//Creation
  Weighted_point_3():data(){}
  Weighted_point_3(double x,double y,double z):data(x,y,z){}
  Weighted_point_3(const Point_3& p,double w):data(p.get_data(),w){}
//Operations    
  double weight() const {return data.weight();}
  double x() const {return data.x();}
  double y() const {return data.y();}
  double z() const {return data.z();}
  Point_3 point() const {return Point_3(data.point());}
//Operators
  DEFINE_EQUALITY_OPERATORS(Weighted_point_3)
//I/O
  std::string toString(){
    std::stringstream sstr;
    sstr << data;
    return sstr.str();
  }
//Deep copy
  typedef Weighted_point_3 Self;
  Self deepcopy() const {return Self(data);}
  void deepcopy(const Self& other){data=other.get_data();}
};

#endif //SWIG_CGAL_KERNEL_WEIGHTED_POINT_3_H
