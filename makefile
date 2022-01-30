##
#
# makefile : build instructions for the project.
#
# See `LICENSE' for full license.
# See `README.md' for project details.
#
##

##
#
# Copyright (C) 2021 Kevin Matthes
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
##

################################################################################

##
#
# Variables.
#
##

# Software.
COPY	:= cp
REMOVE	:= rm

# Make directories.
MLIB	:= -C ./lib/

# Directories.
DOXDIR	:= ./lib/html/ ./lib/latex/

# Concrete files.
REFMAN	:= ./lib/latex/refman.pdf



##
#
# Build instructions.
#
##

.PHONY: default doxygen library manual tidy

default: submodule

doxygen: $(REFMAN)

library:
	make $(MLIB) default

manual: $(REFMAN)
	$(COPY) $(REFMAN) ./libellipse.pdf

$(REFMAN):
	make $(MLIB) doxygen

tidy: $(REFMAN)
	$(REMOVE) $(DOXDIR) $(wildcard ./*.pdf) -rf
	make $(MLIB) tidy

################################################################################
