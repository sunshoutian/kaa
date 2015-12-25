/*
 * Copyright 2014 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ILOGGER_HPP_
#define ILOGGER_HPP_

#include <string>

namespace kaa {

enum class LogLevel {
    KAA_TRACE = 0,
    KAA_DEBUG,
    KAA_INFO,
    KAA_WARNING,
    KAA_ERROR,
    KAA_FATAL
};

class ILogger {
public:
    virtual ~ILogger() {}

    virtual void log(LogLevel level, const char *message) const = 0;

    virtual void setClientID(std::string &clientID) = 0;
    virtual std::string getClientID() const = 0;
};

typedef std::shared_ptr<ILogger> LoggerPtr;

}  // namespace kaa


#endif /* ILOGGER_HPP_ */
