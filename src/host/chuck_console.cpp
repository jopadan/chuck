/*----------------------------------------------------------------------------
  ChucK Strongly-timed Audio Programming Language
    Compiler, Virtual Machine, and Synthesis Engine

  Copyright (c) 2003 Ge Wang and Perry R. Cook. All rights reserved.
    http://chuck.stanford.edu/
    http://chuck.cs.princeton.edu/

  This program is free software; you can redistribute it and/or modify
  it under the dual-license terms of EITHER the MIT License OR the GNU
  General Public License (the latter as published by the Free Software
  Foundation; either version 2 of the License or, at your option, any
  later version).

  This program is distributed in the hope that it will be useful and/or
  interesting, but WITHOUT ANY WARRANTY; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  MIT Licence and/or the GNU General Public License for details.

  You should have received a copy of the MIT License and the GNU General
  Public License (GPL) along with this program; a copy of the GPL can also
  be obtained by writing to the Free Software Foundation, Inc., 59 Temple
  Place, Suite 330, Boston, MA 02111-1307 U.S.A.
-----------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------
// file: chuck_console.cpp
// desc: chuck command line console
//
// author: Spencer Salazar (spencer@ccrma.stanford.edu)
// date: Autumn 2005
//-----------------------------------------------------------------------------
#include "chuck_console.h"
#include "util_console.h"


//-----------------------------------------------------------------------------
// name: Chuck_Console()
// desc: ...
//-----------------------------------------------------------------------------
Chuck_Console::Chuck_Console()
{
}


//-----------------------------------------------------------------------------
// name: ~Chuck_Console()
// desc: ...
//-----------------------------------------------------------------------------
Chuck_Console::~Chuck_Console()
{
}


//-----------------------------------------------------------------------------
// name: init()
// desc: ...
//-----------------------------------------------------------------------------
t_CKBOOL Chuck_Console::init()
{
    return TRUE;
}


//-----------------------------------------------------------------------------
// name: nextCommand()
// desc: ...
//-----------------------------------------------------------------------------
t_CKBOOL Chuck_Console::next_command( const string & prompt, string & out )
{
    // the line read
    char * line_read = NULL;

    // read the next line
    line_read = io_readline( prompt.c_str() );
    
    // check to see if EOF encountered
    // do we need more return codes to differentiate between
    // EOF encountered vs. empty line?
    if( line_read == NULL )
    {
        out = "";
        return FALSE;
    }

    // check first character
    if( *line_read != 0 )
    	io_addhistory( line_read );

    // copy the result
    out = line_read;

    // free the thing
    free( line_read );
    
    return TRUE;
}


//-----------------------------------------------------------------------------
// name: nextResult()
// desc: ...
//-----------------------------------------------------------------------------
void Chuck_Console::next_result( const Chuck_Shell_Response &in )
{
    fputs( in.c_str(), stdout );
}



