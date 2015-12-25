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

#ifndef DEFAULTLOGGER_HPP_
#define DEFAULTLOGGER_HPP_

#include "kaa/KaaDefaults.hpp"

#if KAA_LOG_LEVEL > KAA_LOG_LEVEL_NONE

#include "kaa/logging/ILogger.hpp"
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>


#include <string>

namespace kaa {

class DefaultLogger : public ILogger {
public:
    DefaultLogger(std::string clientId, bool toFile): clientId_(clientId), fileFlag(toFile) {
        if (fileFlag) {
            boost::log::aux::add_file_log(clientId.c_str());
        }
    }

    void log(LogLevel level, const char *message) const {
        BOOST_LOG_STREAM_WITH_PARAMS(boost::log::trivial::logger::get(),
                                     (boost::log::keywords::severity = (boost::log::trivial::severity_level)level)) << message;
    }

    void setClientID(std::string &clientID) {
        clientId_ = clientID;
    }

    std::string getClientID() const {
        return clientId_;
    }

protected:
    std::string clientId_;
    bool fileFlag;
};

}  // namespace kaa

#endif

#endif /* DEFAULTLOGGER_HPP_ */
