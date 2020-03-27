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

"""Component that combine function/inputs by do cartesian product on group."""

from ...components.icomponent import IFIPolicyComponent
from ...utils import keyword


class GroupCartesianProductFIPC(IFIPolicyComponent):
    """
    Combine function/inputs by do cartesian product on group.
    """
    def combine(self, function, inputs, verification_set):
        # pylint: disable=unused-argument
        ret = [(s1, s2) for s1 in function for s2 in inputs if s1[keyword.group] == s2[keyword.group]]
        return ret
