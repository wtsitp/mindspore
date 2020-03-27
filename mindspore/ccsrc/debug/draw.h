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
#ifndef MINDSPORE_CCSRC_DEBUG_DRAW_H_
#define MINDSPORE_CCSRC_DEBUG_DRAW_H_

#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include "ir/anf.h"
#include "utils/any.h"
#include "pipeline/parse/resolve.h"

namespace mindspore {
namespace draw {

namespace parse = mindspore::parse;

class Graphviz {
 public:
  Graphviz(const std::string& name, const std::string& filename) : name_(name), filename_(filename), fout_(filename_) {}

  explicit Graphviz(const std::string& name) : name_(name) {}

  virtual ~Graphviz() {}

  virtual void Start() {}
  virtual void End() {}

  virtual std::string Shape(AnfNodePtr node);
  std::string Color(const AnfNodePtr& node);
  std::ostringstream& buffer() { return buffer_; }
  std::ostringstream buffer_;

 protected:
  std::string name_;
  std::string filename_;
  std::ofstream fout_;
};

class BaseDigraph : public Graphviz {
 public:
  BaseDigraph(const std::string& name, const std::string& filename) : Graphviz(name, filename) {}
  explicit BaseDigraph(const std::string& name) : Graphviz(name) {}
  ~BaseDigraph() override = default;

  virtual void Node(AnfNodePtr node, int id = 0) = 0;
  virtual void Edge(AnfNodePtr start, AnfNodePtr end, int idx, int idx_start = 0) = 0;

  void Start() override;
  void End() override;
  virtual void Edge(AnfNodePtr start, FuncGraphPtr end, int id_start);
  void FuncGraphParameters(const FuncGraphPtr& key);
  void SubGraph(const FuncGraphPtr& key, const std::shared_ptr<BaseDigraph>& gsub);

  const std::string& name() const { return name_; }

 protected:
  void Head(const AnfNodePtr& node, int id = 0);
  void Tail(const AnfNodePtr& node, int idx, int id = 0);
  void Tail(const FuncGraphPtr& func_graph);
};

class Digraph : public BaseDigraph {
 public:
  Digraph(const std::string& name, const std::string& filename) : BaseDigraph(name, filename) {}
  explicit Digraph(const std::string& name) : BaseDigraph(name) {}
  ~Digraph() override;

  void Node(AnfNodePtr node, int id = 0) override;
  void Edge(AnfNodePtr start, AnfNodePtr end, int idx, int idx_start = 0) override;
};

class ModelDigraph : public BaseDigraph {
 public:
  ModelDigraph(const std::string& name, const std::string& filename) : BaseDigraph(name, filename) {}
  explicit ModelDigraph(const std::string& name) : BaseDigraph(name) {}
  ~ModelDigraph() override;

  std::string Shape(AnfNodePtr node) override;
  void Node(AnfNodePtr node, int id = 0) override;
  void Edge(AnfNodePtr start, AnfNodePtr end, int idx, int idx_start = 0) override;
};

// API to draw
void Draw(const std::string& filename, const FuncGraphPtr& func_graph);
void DrawUserFuncGraph(const std::string& filename, const FuncGraphPtr& func_graph);

}  // namespace draw
}  // namespace mindspore

#endif  // MINDSPORE_CCSRC_DEBUG_DRAW_H_
