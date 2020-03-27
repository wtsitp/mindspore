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

"""ZerosLike op"""
from mindspore.ops.op_info_register import op_info_register


@op_info_register("""{
    "op_name": "ZerosLike",
    "imply_type": "TBE",
    "fusion_type": "ELEMWISE",
    "async_flag": false,
    "binfile_name": "zeros_like.so",
    "compute_cost": 10,
    "kernel_name": "zeros_like",
    "partial_flag": true,
    "attr": [

    ],
    "inputs": [
        {
            "index": 0,
            "dtype": [
                "float16","float16","float","float","int32","int32","int8","int8","uint8","uint8","bool","bool"
            ],
            "format": [
                "DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0",
                "DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0"
            ],
            "name": "x",
            "need_compile": false,
            "param_type": "required",
            "shape": "all"
        }
    ],
    "outputs": [
         {
            "index": 0,
            "dtype": [
                "float16","float16","float","float","int32","int32","int8","int8","uint8","uint8","bool","bool"
            ],
            "format": [
                "DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0",
                "DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0","DefaultFormat","NC1HWC0"
            ],
            "name": "y",
            "param_type": "required",
            "shape": "all"
        }
    ]
}""")
def _zeros_like_tbe():
    """ZerosLike TBE register"""
    return
