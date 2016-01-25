// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 10 "vcd.y" // lalr1.cc:404

/*
 * Copyright (c) 2013-2013 Wei Song <songw@cs.man.ac.uk> 
 *    Advanced Processor Technologies Group, School of Computer Science
 *    University of Manchester, Manchester M13 9PL UK
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

/* 
 * Bison grammer file for Value Change Dump (VCD)
 * 28/06/2013   Wei Song
 *
 *
 */

#include "vcd_util.hpp"
  
#define yylex lexer->lexer

  using namespace vcd;


#line 73 "vcd.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "vcd.hh"

// User implementation prologue.

#line 87 "vcd.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "vcd.y" // lalr1.cc:479
namespace vcd {
#line 154 "vcd.cc" // lalr1.cc:479

  /// Build a parser object.
  vcd_parser::vcd_parser (vcd::VCDLexer* lexer_yyarg, vcd::WaveDB* db_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      db (db_yyarg)
  {}

  vcd_parser::~vcd_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  vcd_parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  vcd_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  vcd_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  vcd_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  vcd_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  vcd_parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  vcd_parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  vcd_parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  vcd_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  vcd_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  vcd_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  vcd_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  vcd_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  vcd_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  vcd_parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  vcd_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  vcd_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  vcd_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  vcd_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  vcd_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  vcd_parser::symbol_number_type
  vcd_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  vcd_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  vcd_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  vcd_parser::stack_symbol_type&
  vcd_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  vcd_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  vcd_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  vcd_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  vcd_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  vcd_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  vcd_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  vcd_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  vcd_parser::debug_level_type
  vcd_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  vcd_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline vcd_parser::state_type
  vcd_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  vcd_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  vcd_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  vcd_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 49 "vcd.y" // lalr1.cc:741
{
}

#line 484 "vcd.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 12:
#line 104 "vcd.y" // lalr1.cc:859
    { db->pop_scope(); }
#line 589 "vcd.cc" // lalr1.cc:859
    break;

  case 17:
#line 113 "vcd.y" // lalr1.cc:859
    { }
#line 595 "vcd.cc" // lalr1.cc:859
    break;

  case 18:
#line 114 "vcd.y" // lalr1.cc:859
    { }
#line 601 "vcd.cc" // lalr1.cc:859
    break;

  case 19:
#line 118 "vcd.y" // lalr1.cc:859
    {
      db->push_scope((yystack_[0].value.tStr));
    }
#line 609 "vcd.cc" // lalr1.cc:859
    break;

  case 20:
#line 124 "vcd.y" // lalr1.cc:859
    {
      db->set_time_unit((yystack_[1].value.tNum).get_ui(), timeunit_stype((yystack_[0].value.tType)));
    }
#line 617 "vcd.cc" // lalr1.cc:859
    break;

  case 21:
#line 130 "vcd.y" // lalr1.cc:859
    {
      db->add_id((yystack_[1].value.tStr), (yystack_[0].value.tCId).first, (yystack_[0].value.tCId).second, (yystack_[2].value.tNum).get_ui());
    }
#line 625 "vcd.cc" // lalr1.cc:859
    break;

  case 22:
#line 136 "vcd.y" // lalr1.cc:859
    {
      (yylhs.value.tCId).first = (yystack_[0].value.tStr);
    }
#line 633 "vcd.cc" // lalr1.cc:859
    break;

  case 23:
#line 140 "vcd.y" // lalr1.cc:859
    {
      (yylhs.value.tCId).first = (yystack_[3].value.tStr);
      (yylhs.value.tCId).second = CRange((yystack_[1].value.tNum).get_ui());
    }
#line 642 "vcd.cc" // lalr1.cc:859
    break;

  case 24:
#line 145 "vcd.y" // lalr1.cc:859
    {
      (yylhs.value.tCId).first = (yystack_[5].value.tStr);
      (yylhs.value.tCId).second = CRange((yystack_[3].value.tNum).get_ui(), (yystack_[1].value.tNum).get_ui());
    }
#line 651 "vcd.cc" // lalr1.cc:859
    break;

  case 29:
#line 158 "vcd.y" // lalr1.cc:859
    {
      db->set_time((yystack_[0].value.tNum));
    }
#line 659 "vcd.cc" // lalr1.cc:859
    break;

  case 34:
#line 172 "vcd.y" // lalr1.cc:859
    {
      db->add_change((yystack_[0].value.tStr), (yystack_[1].value.tValue));
    }
#line 667 "vcd.cc" // lalr1.cc:859
    break;

  case 35:
#line 178 "vcd.y" // lalr1.cc:859
    { db->add_change((yystack_[0].value.tStr), (yystack_[1].value.tBValue)); }
#line 673 "vcd.cc" // lalr1.cc:859
    break;

  case 36:
#line 180 "vcd.y" // lalr1.cc:859
    { db->add_change((yystack_[0].value.tStr), (yystack_[1].value.tReal)); }
#line 679 "vcd.cc" // lalr1.cc:859
    break;

  case 37:
#line 183 "vcd.y" // lalr1.cc:859
    { (yylhs.value.tStr) = (yystack_[0].value.tStr); }
#line 685 "vcd.cc" // lalr1.cc:859
    break;


#line 689 "vcd.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  vcd_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  vcd_parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char vcd_parser::yypact_ninf_ = -28;

  const signed char vcd_parser::yytable_ninf_ = -27;

  const signed char
  vcd_parser::yypact_[] =
  {
      51,    -4,    -4,     8,     5,    21,    39,    30,    -4,    46,
      28,   -28,   -28,   -28,     0,     1,   -28,    31,    47,    52,
      48,   -28,    43,    62,     3,   -28,    23,    31,    49,    50,
      53,    -2,   -28,    66,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,    31,   -28,   -28,
       4,   -28,   -28,   -28,    31,    31,   -28,   -28,    31,   -28,
     -28,   -28,   -28,   -28,    54,    56,   -13,   -28,    57,    45,
     -28
  };

  const unsigned char
  vcd_parser::yydefact_[] =
  {
       0,    16,    16,     0,     0,     0,     0,     0,    16,     0,
       0,     3,     7,    17,     0,     0,     9,     0,     0,     0,
       0,    12,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     2,     4,     7,     5,    28,    27,    32,    33,    15,
      18,     8,    37,    19,    10,    20,    11,     0,    13,    14,
       0,    30,    34,    29,     0,     0,    26,     6,     0,    25,
      31,    35,    36,    21,    22,     0,     0,    23,     0,     0,
      24
  };

  const signed char
  vcd_parser::yypgoto_[] =
  {
     -28,   -28,   -28,   -28,    60,    -5,     6,   -28,   -28,   -28,
     -28,    40,   -28,   -28,   -25,   -28,   -28,   -27
  };

  const signed char
  vcd_parser::yydefgoto_[] =
  {
      -1,     9,    10,    31,    11,    12,    14,    18,    20,    23,
      63,    34,    35,    50,    36,    37,    38,    43
  };

  const signed char
  vcd_parser::yytable_[] =
  {
      52,    51,     1,    39,    41,    33,    49,    59,    15,    67,
      68,    16,    13,    26,    24,    27,    40,    40,    17,    40,
      58,    27,    28,    29,    30,    60,    56,    61,    62,    29,
      30,    64,     1,     2,     3,     4,     5,     6,     7,     8,
      27,    19,    21,    26,    22,    27,    25,    42,    29,    30,
      44,    46,    28,    29,    30,     1,     2,     3,     4,     5,
       6,     7,     8,    47,    45,    48,   -26,    70,    54,    53,
      32,    57,    55,     0,     0,    65,    66,    69
  };

  const signed char
  vcd_parser::yycheck_[] =
  {
      27,    26,     4,     3,     3,    10,     3,     3,     2,    22,
      23,     3,    16,    15,     8,    17,    16,    16,    13,    16,
      47,    17,    24,    25,    26,    50,    31,    54,    55,    25,
      26,    58,     4,     5,     6,     7,     8,     9,    10,    11,
      17,    20,     3,    15,    14,    17,     0,    16,    25,    26,
       3,     3,    24,    25,    26,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    12,     3,     0,    22,    18,    20,
      10,    31,    19,    -1,    -1,    21,    20,    20
  };

  const unsigned char
  vcd_parser::yystos_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    11,    28,
      29,    31,    32,    16,    33,    33,     3,    13,    34,    20,
      35,     3,    14,    36,    33,     0,    15,    17,    24,    25,
      26,    30,    31,    32,    38,    39,    41,    42,    43,     3,
      16,     3,    16,    44,     3,    12,     3,    20,     3,     3,
      40,    41,    44,    20,    18,    19,    32,    38,    44,     3,
      41,    44,    44,    37,    44,    21,    20,    22,    23,    20,
      22
  };

  const unsigned char
  vcd_parser::yyr1_[] =
  {
       0,    27,    28,    29,    29,    30,    30,    31,    31,    31,
      31,    31,    31,    31,    31,    32,    33,    33,    33,    34,
      35,    36,    37,    37,    37,    38,    38,    38,    38,    39,
      40,    40,    41,    41,    42,    43,    43,    44
  };

  const unsigned char
  vcd_parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     1,     2,     1,     3,     2,
       3,     3,     2,     3,     3,     3,     0,     1,     2,     2,
       2,     4,     1,     4,     6,     3,     1,     1,     1,     2,
       1,     2,     1,     1,     2,     3,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const vcd_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"$end\"", "\"$comment\"", "\"$date\"",
  "\"$enddefinitions\"", "\"$scope\"", "\"$timescale\"", "\"$upscope\"",
  "\"$var\"", "\"$version\"", "VCDTimeUnit", "VCDScopeType", "VCDVarType",
  "VCDSimCmdType", "VCDStr", "VCDValue", "VCDBValue", "VCDReal", "VCDNum",
  "'['", "']'", "':'", "'#'", "'b'", "'r'", "$accept",
  "value_change_dump_definitions", "declaration_commands",
  "simulation_commands", "declaration_command", "comment_command",
  "comments", "scope_decl", "timescale_decl", "var_decl",
  "complex_identifier", "simulation_command", "simulation_time",
  "value_changes", "value_change", "scalar_value_change",
  "vector_value_change", "identifier", YY_NULLPTR
  };


  const unsigned char
  vcd_parser::yyrline_[] =
  {
       0,    86,    86,    89,    90,    93,    94,    98,    99,   100,
     101,   102,   103,   105,   106,   109,   111,   113,   114,   117,
     123,   129,   135,   139,   144,   151,   152,   153,   154,   157,
     163,   164,   167,   168,   171,   177,   179,   183
  };

  // Print the state stack on the debug stream.
  void
  vcd_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  vcd_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  vcd_parser::token_number_type
  vcd_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    24,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,    25,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
    };
    const unsigned int user_token_number_max_ = 275;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "vcd.y" // lalr1.cc:1167
} // vcd
#line 1061 "vcd.cc" // lalr1.cc:1167
#line 185 "vcd.y" // lalr1.cc:1168


void vcd::vcd_parser::error (const std::string& msg) {
  std::cout << ":" << msg << std::endl;
  }

