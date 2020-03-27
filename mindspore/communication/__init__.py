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
"""
Collective communication interface.
"""

from .management import GlobalComm, init, release, get_rank, get_group_size, get_world_rank_from_group_rank, \
    get_group_rank_from_world_rank, create_group, HCCL_WORLD_COMM_GROUP, NCCL_WORLD_COMM_GROUP, get_group, \
    get_local_rank, get_local_rank_size, destroy_group


__all__ = [
    "GlobalComm", "init", "release", "get_rank", "get_group_size", "get_world_rank_from_group_rank",
    "get_group_rank_from_world_rank", "create_group", "HCCL_WORLD_COMM_GROUP", "NCCL_WORLD_COMM_GROUP", "get_group",
    "get_local_rank", "get_local_rank_size", "destroy_group"
]
