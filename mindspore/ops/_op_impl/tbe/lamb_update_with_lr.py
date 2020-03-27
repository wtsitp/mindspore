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

"""LambUpdateWithLr op"""
from mindspore.ops.op_info_register import op_info_register


@op_info_register("""{
    "op_name":"LambUpdateWithLR",
    "imply_type":"TBE",
    "fusion_type":"ELEMWISE",
    "async_flag":false,
    "binfile_name":"lamb_update_with_lr.so",
    "compute_cost":10,
    "kernel_name":"lamb_update_with_lr",
    "partial_flag":true,
    "attr":[],
    "inputs":[
        {
            "index":0,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input1",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":1,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input2",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":2,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input3",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":3,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input4",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":4,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input5",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":5,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input6",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":6,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input7",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":7,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input8",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        },
        {
            "index":8,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"input9",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        }
    ],
    "outputs":[
        {
            "index":0,
            "dtype":[
                "float16",
                "float32"
            ],
            "format":[
                "DefaultFormat",
                "DefaultFormat"
            ],
            "name":"output_y",
            "need_compile":false,
            "param_type":"required",
            "shape":"all"
        }
    ]
}""")
def _lamb_update_with_lr_tbe():
    """LambUpdateWithLr TBE register"""
    return
