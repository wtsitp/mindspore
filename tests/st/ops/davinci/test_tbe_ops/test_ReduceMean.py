# Copyright 2020 Huawei Technologies Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ============================================================================
from mindspore import Tensor
from mindspore.ops import operations as P
import mindspore.nn as nn
from mindspore.common.api import ms_function
import numpy as np
import mindspore.context as context
from mindspore.common.initializer import initializer
from mindspore.common.parameter import Parameter
context.set_context(device_target="Ascend")
class Net(nn.Cell):
    def __init__(self, keep_dims, axis):
        super(Net, self).__init__()
        self.reduce_mean = P.ReduceMean(keep_dims=keep_dims)
        self.axis = axis

    @ms_function
    def construct(self, inputs):
        return self.reduce_mean(inputs, self.axis)

x1 = np.random.randn(64).astype(np.float32)

def test_net():
    keepdims = False
    axis = -1
    Reduce_mean = Net(keepdims, axis)
    output = Reduce_mean(Tensor(x1))
    print(x1)
    print(output.asnumpy())
