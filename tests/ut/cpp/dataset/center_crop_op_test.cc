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
#include "common/common.h"
#include "common/cvop_common.h"
#include "dataset/kernels/image/center_crop_op.h"
#include "dataset/core/cv_tensor.h"
#include "utils/log_adapter.h"

using namespace mindspore::dataset;
using mindspore::MsLogLevel::INFO;
using mindspore::ExceptionType::NoExceptionType;
using mindspore::LogStream;

class MindDataTestCenterCropOp : public UT::CVOP::CVOpCommon {
 public:
  MindDataTestCenterCropOp() : CVOpCommon() {}
};

TEST_F(MindDataTestCenterCropOp, TestOp) {
  MS_LOG(INFO) << "Doing MindDataTestCenterCropOp::TestOp.";
  std::shared_ptr<Tensor> output_tensor;
  int het = 256;
  int wid = 128;
  std::unique_ptr<CenterCropOp> op(new CenterCropOp(het, wid));
  EXPECT_TRUE(op->OneToOne());
  Status s = op->Compute(input_tensor_, &output_tensor);
  EXPECT_TRUE(s.IsOk());
  EXPECT_EQ(het, output_tensor->shape()[0]);
  EXPECT_EQ(wid, output_tensor->shape()[1]);
  std::shared_ptr<CVTensor> p = CVTensor::AsCVTensor(output_tensor);
}
