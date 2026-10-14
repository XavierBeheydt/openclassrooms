#!/usr/bin/env python3
# coding: utf-8

# Import without make module as lib
# import csv_analysis as c_an 
# import xml_analysis as x_an

# import as lib
import parser.csv as csv
import parser.xml as xml

import argparse
import logging as log

def parser_arguments():
    parser = argparse.ArgumentParser()
    
    parser.add_argument("-e", "--extension", 
        help="""Type of file to analyse. It is a CSV or en XML?""")
    parser.add_argument("-d", "--datafile", 
        help="""CSV containing pieces of information""" 
    """about the members of parliament""")
    parser.add_argument("-v", "--verbose", action='store_true',
        help="""Activate verbose""")

    return parser.parse_args()


def main():
    args = parser_arguments()
    if args.verbose:
        log.basicConfig(level=log.DEBUG)

    try:
        datafile = args.datafile
        if datafile == None:
            # Levée d'exception
            raise Warning("You must indicate a datafile!")
        else:
            try:
                if args.extension == 'xml':
                    xml.launch_analysis(datafile)
                else:
                    csv.launch_analysis(datafile)
            except FileNotFoundError as err:
                print('Error: File specified not found :', err)
            finally:
                log.info("==================== Analysis is over ==================")
    except Warning as err:
        log.warning(err)


if __name__ == "__main__":
    # Import de la lib de debug et lancement du tracage
    # Il faut bien pensé à retirer cela après
    # import pdb; pdb.set_trace()
    main()
