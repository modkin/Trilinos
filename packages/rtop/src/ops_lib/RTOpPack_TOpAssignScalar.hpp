// @HEADER
// ***********************************************************************
// 
// RTOp: Interfaces and Support Software for Vector Reduction Transformation
//       Operations
//                Copyright (2006) Sandia Corporation
// 
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Roscoe A. Bartlett (rabartl@sandia.gov) 
// 
// ***********************************************************************
// @HEADER

#ifndef RTOPPACK_TOP_ASSIGN_SCALAR_HPP
#define RTOPPACK_TOP_ASSIGN_SCALAR_HPP

#include "RTOpPack_RTOpTHelpers.hpp"


namespace RTOpPack {


/** \brief Element-wise transformation operator for TOpAssignScalar. */
template<class Scalar>
class TOpAssignScalarEleWiseTransformation
{
public:
  TOpAssignScalarEleWiseTransformation( const Scalar &alpha )
    {
      alpha_ = alpha;
    }
  void operator()( Scalar &z0 ) const
    {
      z0 = alpha_;
    }
private:
  Scalar alpha_;
  TOpAssignScalarEleWiseTransformation(); // Not defined
};


/** \brief Assign a scalar to a vector transformation operator: <tt>z0[i] =
 * alpha, i=0...n-1</tt>.
 */
template<class Scalar>
class TOpAssignScalar
  : public TOp_0_1_Base<Scalar, TOpAssignScalarEleWiseTransformation<Scalar> >
{
public:
  typedef TOp_0_1_Base<Scalar, TOpAssignScalarEleWiseTransformation<Scalar> > base_t;
  /** \brief . */
  TOpAssignScalar( const Scalar &alpha )
    : base_t(TOpAssignScalarEleWiseTransformation<Scalar>(alpha))
    {
      this->setOpNameBase("TOpAssignScalar");
    }
};


} // namespace RTOpPack


#endif // RTOPPACK_TOP_ASSIGN_SCALAR_HPP
