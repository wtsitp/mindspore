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

#ifndef MINDSPORE_CCSRC_KERNEL_HCCL_HCCL_KERNEL_H_
#define MINDSPORE_CCSRC_KERNEL_HCCL_HCCL_KERNEL_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "kernel/kernel.h"
#include "kernel/hccl/hcom_util.h"
#include "hccl/hcom.h"
#include "common/utils.h"

namespace mindspore {
namespace kernel {
class HcclKernel : public KernelMod {
 public:
  HcclKernel();
  ~HcclKernel() override;
  virtual bool Init(const AnfNodePtr &anf_node);
  const std::vector<size_t> &GetInputSizeList() const override;
  const std::vector<size_t> &GetOutputSizeList() const override;
  const std::vector<size_t> &GetWorkspaceSizeList() const override;
  vector<TaskInfoPtr> GenTask(const std::vector<AddressPtr> &inputs, const std::vector<AddressPtr> &workspace,
                              const std::vector<AddressPtr> &outputs, uint32_t stream_id) override;

 protected:
  std::vector<std::vector<size_t>> hccl_kernel_input_shape_list_;
  std::vector<std::vector<size_t>> hccl_kernel_output_shape_list_;
  std::vector<hcclDataType_t> hccl_data_type_list_;
  std::vector<std::string> hccl_format_list_;
  uint64_t hccl_count_;
  hcclRedOp_t op_type_;
  uint32_t root_id_;
  mutable std::vector<size_t> input_size_list_;
  mutable std::vector<size_t> output_size_list_;
  mutable std::vector<size_t> workspace_size_list_;
  AnfNodePtr anf_node_;
  std::string op_name_;
};

using HcclKernelCreater = std::function<std::shared_ptr<HcclKernel>()>;

class HcclKernelFactory {
  HcclKernelFactory() = default;
  ~HcclKernelFactory() = default;

 public:
  static HcclKernelFactory &Get();
  void Registe(const string &name, HcclKernelCreater &&fun);
  static std::shared_ptr<HcclKernel> Get(const string &name);

 private:
  std::map<string, HcclKernelCreater> hcclKernelMap_;
};

class _HcclKernelRegister {
 public:
  _HcclKernelRegister(const string &name, HcclKernelCreater &&fun) {
    HcclKernelFactory::Get().Registe(name, std::move(fun));
  }
  ~_HcclKernelRegister() = default;
};

#define _MS_HCCL_REG_KERNEL_REG(KNAME, clazz)                                              \
  static_assert(std::is_base_of<HcclKernel, clazz>::value, " must be base of HcclKernel"); \
  static const _HcclKernelRegister g_##KNAME##_##_kernel_reg(#KNAME, []() {                \
    std::shared_ptr<clazz> ptr = nullptr;                                                  \
    ptr = std::make_shared<clazz>();                                                       \
    MS_EXCEPTION_IF_NULL(ptr);                                                             \
    return ptr;                                                                            \
  });

#define MS_HCCL_REG_KERNEL(KNAME, clazz) _MS_HCCL_REG_KERNEL_REG(KNAME, clazz)
}  // namespace kernel
}  // namespace mindspore
#endif
