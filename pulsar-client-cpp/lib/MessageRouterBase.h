/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef PULSAR_CPP_MESSAGEROUTERBASE_H
#define PULSAR_CPP_MESSAGEROUTERBASE_H

#include <boost/interprocess/smart_ptr/unique_ptr.hpp>
#include <boost/checked_delete.hpp>

#include <pulsar/MessageRoutingPolicy.h>
#include <pulsar/ProducerConfiguration.h>
#include "Hash.h"

namespace pulsar {
typedef boost::interprocess::unique_ptr<Hash, boost::checked_deleter<Hash> > HashPtr;

class MessageRouterBase : public MessageRoutingPolicy {
   public:
    MessageRouterBase(ProducerConfiguration::HashingScheme hashingScheme);

   protected:
    HashPtr hash;
};
}  // namespace pulsar

#endif  // PULSAR_CPP_MESSAGEROUTERBASE_H
