#!/bin/bash

if ! command -v brew &> /dev/null
then
    echo "Homebrew not found. Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
else
    echo "Homebrew already installed"
fi

brew update

brew install cmake
brew install opencv
brew install git
brew install qt
brew install fmt

#(QPixmap, QObject, QMutex, etc.)
brew install qt@6

#environment variables for CMake
export CMAKE_PREFIX_PATH="$(brew --prefix qt@6)"

#check if installed correctly
if ! [ -d "$(brew --prefix qt@6)" ]; then
  echo "Qt installation failed."
  exit 1
fi

echo "Dependencies installed successfully."
