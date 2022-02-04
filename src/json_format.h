// Copyright 2017 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Modifications Copyright 2022 Code Intelligence GmbH

#ifndef SRC_JSON_FORMAT_H_
#define SRC_JSON_FORMAT_H_

#include <string>

#include "port/protobuf.h"

namespace protobuf_mutator {

// JSON serialization of protos.
bool ParseJsonMessage(const uint8_t* data, size_t size,
                      protobuf::Message* output);
bool ParseJsonMessage(const std::string& data, protobuf::Message* output);
size_t SaveMessageAsJson(const protobuf::Message& message, uint8_t* data,
                         size_t max_size);
std::string SaveMessageAsJson(const protobuf::Message& message);

}  // namespace protobuf_mutator

#endif  // SRC_JSON_FORMAT_H_
