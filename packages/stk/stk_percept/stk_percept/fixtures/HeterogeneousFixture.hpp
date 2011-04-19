/*------------------------------------------------------------------------*/
/*                 Copyright 2010, 2011 Sandia Corporation.                     */
/*  Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive   */
/*  license for use of this work by or on behalf of the U.S. Government.  */
/*  Export of this program may require a license from the                 */
/*  United States Government.                                             */
/*------------------------------------------------------------------------*/

#ifndef stk_percept_HeterogeneousFixture_hpp
#define stk_percept_HeterogeneousFixture_hpp

#include <Shards_BasicTopologies.hpp>

#include <stk_util/parallel/Parallel.hpp>

#include <stk_mesh/base/Types.hpp>
#include <stk_mesh/fem/FEMMetaData.hpp>
#include <stk_mesh/base/BulkData.hpp>
#include <stk_mesh/base/Entity.hpp>
#include <stk_mesh/base/Field.hpp>
#include <stk_mesh/base/FieldData.hpp>

#include <stk_mesh/fem/CoordinateSystems.hpp>
#include <stk_mesh/fem/Stencils.hpp>
#include <stk_mesh/fem/TopologyDimensions.hpp>

#include <stk_mesh/base/Part.hpp>
#include <stk_mesh/base/Field.hpp>
#include <stk_mesh/base/FieldData.hpp>

#include <stk_mesh/fem/CoordinateSystems.hpp>

#include <stk_percept/fixtures/HeterogeneousFixture.hpp>

/** stk_mesh Use Case 3 - copied and modified here */

#define HET_FIX_INCLUDE_EXTRA_ELEM_TYPES 0

namespace stk {
  namespace percept {

    typedef stk::mesh::Field<double, stk::mesh::Cartesian>    VectorFieldType ;
    typedef stk::mesh::Field<double>                          ScalarFieldType ;
    typedef stk::mesh::Field<double*, stk::mesh::ElementNode> ElementNodePointerFieldType ;

    /** Use case with mixed element topologies and
     *  field relations to provide fast access to node field data
     *  from an element.
     *
     *  copied from stk_mesh and modified
     */

    class HeterogeneousFixture {
    public:


      ~HeterogeneousFixture();

      HeterogeneousFixture( stk::ParallelMachine comm, bool doCommit = true);

      void populate();

      const int m_spatial_dimension;
      stk::mesh::fem::FEMMetaData m_metaData;
      stk::mesh::BulkData m_bulkData;

      stk::mesh::Part & m_block_hex;
      stk::mesh::Part & m_block_wedge;
      stk::mesh::Part & m_block_tet;
#if HET_FIX_INCLUDE_EXTRA_ELEM_TYPES
      stk::mesh::Part & m_block_pyramid;
      stk::mesh::Part & m_block_quad_shell;
      stk::mesh::Part & m_block_tri_shell;
#endif
      const stk::mesh::EntityRank m_elem_rank;

      VectorFieldType & m_coordinates_field;
      VectorFieldType & m_centroid_field;
      ScalarFieldType & m_temperature_field;
      ScalarFieldType & m_volume_field;
      ElementNodePointerFieldType & m_element_node_coordinates_field;
    };

    bool verifyMesh( const HeterogeneousFixture & mesh );

  } //namespace percept
} //namespace stk

#endif // Stk_Mesh_Use_Cases_UseCase_3_hpp
