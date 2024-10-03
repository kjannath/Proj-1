FROM mcr.microsoft.com/devcontainers/cpp:1-debian-12

# Install dos2unix
RUN apt-get update && apt-get install -y dos2unix

# Download doctest into /usr/local/include
RUN wget -O /usr/local/include/doctest.h https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h

CMD ["/bin/bash"]

