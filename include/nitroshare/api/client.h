/*
 * libnitroshareapi
 * Copyright (C) 2013  Nathan Osman
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 */

#ifndef NSA_CLIENT_H
#define NSA_CLIENT_H

#include <QObject>

#include "export.h"

namespace NitroShare
{
    namespace API
    {
        class NSA_EXPORT ClientPrivate;

        /**
         * @brief Client for communicating with the NitroShare API
         */
        class NSA_EXPORT Client : public QObject
        {
            Q_OBJECT

            public:

                /**
                 * @brief Creates the API client
                 * @param parent the parent QObject
                 */
                explicit Client(QObject * parent);

                /**
                 * @brief Destroys the client
                 */
                virtual ~Client();

                /**
                 * @brief Sets the API key to use for requests
                 * @param key the API key
                 */
                void setKey(QString key);

                /**
                 * @brief Sets the access token to use for requests
                 * @param token the access token
                 */
                void setAccessToken(QString token);

            private:

                ClientPrivate * const d;
        };
    }
}

#endif // NSA_CLIENT_H
