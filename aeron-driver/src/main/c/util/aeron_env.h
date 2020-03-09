/*
 * Copyright 2014-2020 Real Logic Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AERON_AERON_ENV_H
#define AERON_AERON_ENV_H

#include <stdlib.h>

inline int aeron_env_set(const char *key, const char *val)
{
#if !defined(WIN32)
    return setenv(key, val, 1);
#else
    return _putenv_s(key, val);
#endif
}

inline int aeron_env_unset(const char *key)
{
#if !defined(WIN32)
    return unsetenv(key);
#else
    return _putenv_s(key, "");
#endif
}

#endif //AERON_AERON_ENV_H
