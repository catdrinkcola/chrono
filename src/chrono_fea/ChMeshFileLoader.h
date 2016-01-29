// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All right reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Andrea Favali, Alessandro Tasora
// =============================================================================
// Utilities for loading meshes from file
// =============================================================================

#ifndef CHMESH_FILE_LOADER_H
#define CHMESH_FILE_LOADER_H

#include "ChMesh.h"

namespace chrono {
namespace fea {

/// @addtogroup fea
/// @{

/// Collection of mesh file loader utilities.
class ChApiFea ChMeshFileLoader {
  public:
    /// Load tetahedrons from .node and .ele files as saved by TetGen.
    /// The file format for .node (with point# starting from 1) is:
    ///   [# of points] [dimension (only 3)] [# of attributes (only 0)] [markers (only 0)]
    ///   [node #] [x] [y] [z]
    ///   [node #] [x] [y] [z]   etc.
    /// The file format for .ele (with tet# starting from 1) is:
    ///   [# of tetahedrons] [dimension (only 4 supported)] [# of attributes (only 0)]
    ///   [tet #] [node #] [node #] [node #] [node #]
    ///   [tet #] [node #] [node #] [node #] [node #]   etc.
    /// If you pass a material inherited by ChContinuumElastic, nodes with 3D motion are used, and corotational
    /// elements.
    /// If you pass a material inherited by ChContinuumPoisson3D, nodes with scalar field are used (ex. thermal,
    /// electrostatics, etc)
    static void FromTetGenFile(
        ChSharedPtr<ChMesh> mesh,                      ///< destination mesh
        const char* filename_node,                     ///< name of the .node file
        const char* filename_ele,                      ///< name of the .ele  file
        ChSharedPtr<ChContinuumMaterial> my_material,  ///< material for the created tetahedrons
        ChVector<> pos_transform = VNULL,              ///< optional displacement of imported mesh
        ChMatrix33<> rot_transform = ChMatrix33<>(1)   ///< optional rotation/scaling of imported mesh
    );

    /// Load tetahedrons, if any, saved in a .inp file for Abaqus.
    static void FromAbaqusFile(
        ChSharedPtr<ChMesh> mesh,                                           ///< destination mesh
        const char* filename,                                               ///< input file name
        ChSharedPtr<ChContinuumMaterial> my_material,                       ///< material for the created tetahedrons
        std::vector<std::vector<ChSharedPtr<ChNodeFEAbase> > >& node_sets,  ///< vect of vectors of 'marked'nodes
        ChVector<> pos_transform = VNULL,                                   ///< optional displacement of imported mesh
        ChMatrix33<> rot_transform = ChMatrix33<>(1),  ///< optional rotation/scaling of imported mesh
        bool discard_unused_nodes = true  ///< if true, Abaqus nodes that are not used in elements or sets are not imported in C::E
        );
};

/// @} fea

}  // end namespace fea
}  // end namespace chrono

#endif
