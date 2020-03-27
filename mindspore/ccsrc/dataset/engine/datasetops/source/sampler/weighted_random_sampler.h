/**
 * Copyright 2019 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef DATASET_ENGINE_DATASETOPS_SOURCE_SAMPLER_WEIGHTED_RANDOM_SAMPLER_H_
#define DATASET_ENGINE_DATASETOPS_SOURCE_SAMPLER_WEIGHTED_RANDOM_SAMPLER_H_

#include <deque>
#include <limits>
#include <memory>
#include <vector>

#include "dataset/engine/datasetops/source/sampler/sampler.h"

namespace mindspore {
namespace dataset {
// Samples elements from id `0, 1, ..., weights.size()-1` with given probabilities (weights).
class WeightedRandomSampler : public Sampler {
 public:
  // Constructor.
  // @param weights A lift of sample weights.
  // @param num_samples Number of samples to be drawn.
  // @param replacement Determine if samples are drawn with/without replacement.
  // @param samples_per_buffer The number of ids we draw on each call to GetNextBuffer().
  // When samplesPerBuffer=0, GetNextBuffer() will draw all the sample ids and return them at once.
  WeightedRandomSampler(const std::vector<double> &weights, int64_t num_samples, bool replacement = true,
                        int64_t samples_per_buffer = std::numeric_limits<int64_t>::max());

  // Destructor.
  ~WeightedRandomSampler() = default;

  // Initialize the sampler.
  // @param op (Not used in this sampler)
  // @return Status
  Status Init(const RandomAccessOp *op) override;

  // Reset the internal variable to the initial state and reshuffle the indices.
  Status Reset() override;

  // Get the sample ids.
  // @param[out] out_buffer The address of a unique_ptr to DataBuffer where the sample ids will be placed.
  // @note the sample ids (int64_t) will be placed in one Tensor and be placed into pBuffer.
  Status GetNextBuffer(std::unique_ptr<DataBuffer> *out_buffer) override;

 private:
  // A list of weights for each sample.
  std::vector<double> weights_;

  // A flag indicating if samples are drawn with/without replacement.
  bool replacement_;

  // Current sample id.
  int64_t sample_id_;

  // Current buffer id.
  int64_t buffer_id_;

  // Random engine and device
  std::mt19937 rand_gen_;

  // Discrete distribution for generating weighted random numbers with replacement.
  std::unique_ptr<std::discrete_distribution<int64_t>> discrete_dist_;

  // Exponential distribution for generating weighted random numbers without replacement.
  // based on "Accelerating weighted random sampling without replacement" by Kirill Muller.
  std::unique_ptr<std::exponential_distribution<>> exp_dist_;

  // Initialized the computation for generating weighted random numbers without replacement
  // using onepass method.
  void InitOnePassSampling();

  // Store the random weighted ids generated by onepass method in `InitOnePassSampling`
  std::deque<int64_t> onepass_ids_;
};
}  // namespace dataset
}  // namespace mindspore

#endif
