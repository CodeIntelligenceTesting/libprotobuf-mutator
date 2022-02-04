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

#include "src/json_format.h"

#include "port/protobuf.h"

namespace protobuf_mutator {

using protobuf::Message;
using protobuf::util::JsonStringToMessage;
using protobuf::util::MessageToJsonString;

bool ParseJsonMessage(const uint8_t* data, size_t size, Message* output) {
  return ParseJsonMessage({reinterpret_cast<const char*>(data), size}, output);
}

bool ParseJsonMessage(const std::string& data, protobuf::Message* output) {
  output->Clear();
  if (!JsonStringToMessage(data, output).ok()) {
    output->Clear();
    return false;
  }
  return true;
}

size_t SaveMessageAsJson(const Message& message, uint8_t* data,
                         size_t max_size) {
  std::string result;
  MessageToJsonString(message, &result);
  if (result.size() <= max_size) {
    memcpy(data, result.data(), result.size());
    return result.size();
  }
  return 0;
}

std::string SaveMessageAsJson(const protobuf::Message& message) {
  std::string result;
  if (!MessageToJsonString(message, &result).ok()) return {};
  return result;
}

}  // namespace protobuf_mutator