#!/bin/sh

##################################################################################
#  __  __ _       _                     _       
# |  \/  (_)_ __ (_) ___ ___  _ __   __| | __ _ 
# | |\/| | | '_ \| |/ __/ _ \| '_ \ / _` |/ _` |
# | |  | | | | | | | (_| (_) | | | | (_| | (_| |
# |_|  |_|_|_| |_|_|\___\___/|_| |_|\__,_|\__,_|
#
#  ___       _       _ _                       _       
# |_ _|_ __ | |_ ___| (_) __ _  ___ _ __   ___(_) __ _ 
#  | || '_ \| __/ _ \ | |/ _` |/ _ \ '_ \ / __| |/ _` |
#  | || | | | ||  __/ | | (_| |  __/ | | | (__| | (_| |
# |___|_| |_|\__\___|_|_|\__, |\___|_| |_|\___|_|\__,_|
#                        |___/                         
#     _         _   _  __ _      _       _ 
#    / \   _ __| |_(_)/ _(_) ___(_) __ _| |
#   / _ \ | '__| __| | |_| |/ __| |/ _` | |
#  / ___ \| |  | |_| |  _| | (__| | (_| | |
# /_/   \_\_|   \__|_|_| |_|\___|_|\__,_|_|
                                         
# Miniconda Inteligencia Artificial

# Do you wish to update your shell profile to automatically initialize conda?
# This will activate conda on startup and change the command prompt when activated.
# If you'd prefer that conda's base environment not be activated on startup,
#    run the following command when conda is activated:

# conda config --set auto_activate_base false

# You can undo this by running `conda init --reverse $SHELL`? [yes|no]
# [no] >>> no

# You have chosen to not have conda modify your shell scripts at all.
# To activate conda's base environment in your current shell session:

# eval "$(/home/orphee/miniconda3/bin/conda shell.YOUR_SHELL_NAME hook)" 

# To install conda's shell functions for easier access, first activate, then:

# conda init

# USAR ESTO
# eval "$(/home/orphee/miniconda3/bin/conda shell.zsh hook)" && conda activate amb

# nombre del ambiente: amb

##################################################################################

# run from shell
# $ activate-miniconda.sh

eval "$(/home/orphee/miniconda3/bin/conda shell.zsh hook)" && conda activate amb
