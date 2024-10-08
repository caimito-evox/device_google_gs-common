/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <PowerStatsAidl.h>

namespace aidl {
namespace android {
namespace hardware {
namespace power {
namespace stats {

class TpuDvfsStateResidencyDataProvider : public PowerStats::IStateResidencyDataProvider {
  public:
    TpuDvfsStateResidencyDataProvider(
            const std::string& path, std::vector<std::string> frequencies, uint64_t clockRate);
    ~TpuDvfsStateResidencyDataProvider() = default;

    /*
     * See IStateResidencyDataProvider::getStateResidencies
     */
    bool getStateResidencies(
        std::unordered_map<std::string, std::vector<StateResidency>> *residencies) override;

    /*
     * See IStateResidencyDataProvider::getInfo
     */
    std::unordered_map<std::string, std::vector<State>> getInfo() override;

  private:
    const std::string mPath;
    const std::vector<std::string> mFrequencies;
    const uint64_t mClockRate;
};

}  // namespace stats
}  // namespace power
}  // namespace hardware
}  // namespace android
}  // namespace aidl
