/**
 * Copyright 2020 Huawei Technologies Co., Ltd
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
#include <iostream>
#include <memory>

#include "common/common_test.h"

#include "ir/anf.h"
#include "utils/base_ref.h"

namespace mindspore {
namespace utils {
class TestBaseRef : public UT::Common {
 public:
  TestBaseRef() {}
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(TestBaseRef, TestScalar) {
  BaseRef a = 1;
  BaseRef b = 1.0;
  if (isa<int>(a)) {
    ASSERT_EQ(cast<int>(a), 1);
    Int32ImmPtr c = cast<Int32ImmPtr>(a);
    ASSERT_EQ(cast<int>(c), 1);
  }
  ASSERT_TRUE(isa<Int32Imm>(a));
  ASSERT_TRUE(isa<BaseRef>(a));
  ASSERT_TRUE(isa<double>(b));
  ASSERT_TRUE(isa<FP64Imm>(b));
  BaseRef c = 1;
  ASSERT_EQ(a == c, true);
}

void func(const BaseRef& sexp) {
  if (isa<VectorRef>(sexp)) {
    const VectorRef& a = cast<VectorRef>(sexp);
    for (size_t i = 0; i < a.size(); i++) {
      BaseRef v = a[i];
      MS_LOG(INFO) << "for is i:" << i << ", " << v.ToString() << "\n";
    }
    MS_LOG(INFO) << "in func  is valuesequeue:" << sexp.ToString() << "\n";
  }
}

TEST_F(TestBaseRef, TestNode) {
  AnfNodePtr anf = NewValueNode(1);
  BaseRef d = anf;
  MS_LOG(INFO) << "anf typeid:" << dyn_cast<AnfNode>(anf).get();
  MS_LOG(INFO) << "anf typeid:" << NewValueNode(1)->tid();
  MS_LOG(INFO) << "node reftypeid:" << d.tid();
  ASSERT_EQ(isa<AnfNodePtr>(d), true);
  ASSERT_EQ(isa<AnfNode>(d), true);
  ASSERT_EQ(isa<ValueNode>(d), true);
  AnfNodePtr c = cast<ValueNodePtr>(d);
  ASSERT_NE(c, nullptr);
}

TEST_F(TestBaseRef, TestVector) {
  AnfNodePtr anf = NewValueNode(1);
  VectorRef a({1, 2, anf, NewValueNode(1)});
  ASSERT_TRUE(isa<VectorRef>(a));
  func(a);
  BaseRef b;
  b = 1;
  ASSERT_TRUE(isa<int>(b));
  std::vector<int> int_t({1, 2, 3});
  VectorRef k;
  k.insert(k.end(), int_t.begin(), int_t.end());

  k = a;
  func(k);

  BaseRef c = std::make_shared<VectorRef>(a);
  BaseRef c1 = std::make_shared<VectorRef>(a);
  ASSERT_TRUE(c == c1);

  ASSERT_TRUE(isa<VectorRef>(c));
  VectorRefPtr d = cast<VectorRefPtr>(c);
  ASSERT_TRUE(isa<VectorRef>(d));
  VectorRef e1({1, 2, anf});
  VectorRef e({1, 2, anf});
  ASSERT_EQ(e1 == e, true);
}
}  // namespace utils
}  // namespace mindspore
