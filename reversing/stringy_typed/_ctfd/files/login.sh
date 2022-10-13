#!/bin/bash

FLAG="BEGINNER{REDACTED}"

while true
do
    echo -n "Enter your password: "
    read -r password

    if [ -z "$password" ]
    then
        echo "Password cannot be empty"
    elif [[ "$password" = *" "* ]]
    then
        echo "Password cannot contain spaces"
    else
        break
    fi
done

if [ -n $password ] 2>/dev/null
then
    echo "Login failed!"
else
    echo "Login successful!"
    echo "Here is your flag: $FLAG"
fi
