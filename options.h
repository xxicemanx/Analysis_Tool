#ifndef FILE_SETTINGS_PROGRAM_OPTIONS
#define FILE_SETTINGS_PROGRAM_OPTIONS

#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED

struct Range
{
  double start, step, end;
};

struct Settings
{
  typedef enum {
    NON_EXCLUSIVE    = 1,
    SEMI_EXCLUSIVE_1 = 2,
    SEMI_EXCLUSIVE_2 = 3,
    EXCLUSIVE        = 4
  } MatchType;

  boost::filesystem::path computed_roi_path;
  boost::filesystem::path true_roi_path;
  boost::filesystem::path output_results_path;
  boost::filesystem::path draw_results_folder;
  bool draw_results;
  double overlap_threshold;
  MatchType match_level;
//  bool calculate_score_range;
//  Range score_range;
  double score_threshold; // XXX: Temporary
};

std::istream& operator>> ( std::istream &in, Range& range );

/**LoadSettings****************************************************************\
|    Description: Load the settings from the settings file.  The settings file |
|                 is defined on the command line using the option              |
|                 -s (--settings-file).                                        |
|    Input:                                                                    |
|      argc/argc: command line arguments                                       |
|    Output:                                                                   |
|      settings: program settings                                              |
\******************************************************************************/
void LoadSettings(
  int        argc,
  char       *argv[],
  Settings&  settings
);

/**PrintSettings***************************************************************\
|   Description: Write the settings values to some output stream.              |
|   Input:                                                                     |
|     settings: program settings                                               |
|   Output:                                                                    |
|     out: Output stream to write settings to (ex. std::cout)                  |
\******************************************************************************/
void PrintSettings( const Settings& settings, std::ostream& out );

#endif // FILE_SETTINGS_PROGRAM_OPTIONS

