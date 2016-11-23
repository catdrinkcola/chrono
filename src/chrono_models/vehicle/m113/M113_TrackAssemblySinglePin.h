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
// Authors: Radu Serban
// =============================================================================
//
// M113 single-pin track assembly subsystem.
//
// =============================================================================

#ifndef M113_TRACK_ASSEMBLY_SINGLE_PIN_H
#define M113_TRACK_ASSEMBLY_SINGLE_PIN_H

#include <string>

#include "chrono_vehicle/tracked_vehicle/track_assembly/ChTrackAssemblySinglePin.h"
#include "chrono_models/ChApiModels.h"

namespace chrono {
namespace vehicle {
namespace m113 {

/// M113 track assembly using single-pin track shoes.
class CH_MODELS_API M113_TrackAssemblySinglePin : public ChTrackAssemblySinglePin {
  public:
    M113_TrackAssemblySinglePin(VehicleSide side);

    virtual const ChVector<> GetSprocketLocation() const override;
    virtual const ChVector<> GetIdlerLocation() const override;
    virtual const ChVector<> GetRoadWhelAssemblyLocation(int which) const override;

  private:
    static const ChVector<> m_sprocket_loc;
    static const ChVector<> m_idler_loc;
    static const ChVector<> m_susp_locs_L[5];
    static const ChVector<> m_susp_locs_R[5];
};

}  // end namespace m113
}  // end namespace vehicle
}  // end namespace chrono

#endif
