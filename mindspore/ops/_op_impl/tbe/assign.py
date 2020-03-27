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

"""Assign op"""
from mindspore.ops.op_info_register import op_info_register


@op_info_register("""{
    "op_name": "Assign",
    "imply_type": "TBE",
    "fusion_type": "OPAQUE",
    "async_flag": false,
    "binfile_name": "assign.so",
    "compute_cost": 10,
    "kernel_name": "assign",
    "partial_flag": true,
    "attr": [

    ],
    "inputs": [
        {
            "index": 0,
            "dtype": [
                "float16", "float16", "float16", "float16", "float", "float", "float", "float",
                "int32", "int32", "int32", "int32", "uint32", "uint32", "uint32", "uint32", "int8",
                "int8", "int8", "int8", "uint8", "uint8", "uint8", "uint8", "int16", "int16", "int16",
                "int16", "uint16", "uint16", "uint16", "uint16", "int64", "int64", "int64", "int64",
                "uint64", "uint64", "uint64", "uint64", "float"
            ],
            "format": [
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "FRACTAL_NZ"
            ],
            "name": "resource",
            "need_compile": false,
            "param_type": "required",
            "shape": "all"
        },
        {
            "index": 1,
            "dtype": [
                "float16", "float16", "float16", "float16", "float", "float", "float", "float", "int32", "int32",
                "int32", "int32", "uint32", "uint32", "uint32", "uint32", "int8", "int8", "int8", "int8", "uint8",
                "uint8", "uint8", "uint8", "int16", "int16", "int16", "int16", "uint16", "uint16", "uint16",
                "uint16", "int64", "int64", "int64", "int64", "uint64", "uint64", "uint64", "uint64", "float"
            ],
            "format": [
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "FRACTAL_NZ"
            ],
            "name": "value",
            "need_compile": false,
            "param_type": "required",
            "shape": "all"
        }
    ],
    "outputs": [
        {
            "index": 0,
            "dtype": [
                "float16", "float16", "float16", "float16", "float", "float", "float", "float", "int32",
                "int32", "int32", "int32", "uint32", "uint32", "uint32", "uint32", "int8", "int8", "int8",
                "int8", "uint8", "uint8", "uint8", "uint8", "int16", "int16", "int16", "int16", "uint16",
                "uint16", "uint16", "uint16", "int64", "int64", "int64", "int64",
                "uint64", "uint64", "uint64", "uint64", "float"
            ],
            "format": [
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0",
                "DefaultFormat", "DefaultFormat", "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat",
                "DefaultFormat", "NC1HWC0", "DefaultFormat", "DefaultFormat", "FRACTAL_NZ"
            ],
            "name": "y",
            "param_type": "required",
            "shape": "all"
        }
    ]
}""")
def _assign_tbe():
    """Assign TBE register"""
    return
