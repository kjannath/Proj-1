# This is necessary to comply with the autograder...
FROM eecsautograder/ubuntu24:latest

# Install tools necessary for development environment
RUN apt-get update && \
    apt-get install -y \
        dos2unix \
        wget \
        cppcheck \
        valgrind \
        git

# Download doctest into /usr/local/include
RUN wget -O /usr/local/include/doctest.h https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h
