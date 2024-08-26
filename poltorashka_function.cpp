#include "constants.h"
#include "input_functions.h"
#include "poltorashka_function.h"
#include "solver_functions.h"
#include "output_functions.h"

void cat ()
{
    printf ( "**++++++++++========================================*####*=-================================--====--\n"
    "*##**++++===========================================*####*=-================================--------\n"
    "==+*##***+==========================================*####*=-=====================-===---------------\n"
    "=====+*##***+=======================================*####*=-================------------------------\n"
    "========+*#***+=----------==========================*####*=================-------------------------\n"
    "============*****+=-------==========================*####*==================------------------------\n"
    "=========-----+*****+=----==========================**###+=================-------------------------\n"
    "======-----------+*****+---=========================*####+=================-------------------------\n"
    "====----------------+*#***+=========================*####+=================-------------------------\n"
    "==---------------------+*****+======================*####+================--------------------------\n"
    "-------------------------=**#**++===================*####+=================-------------------------\n"
    "------------------=========-=*#*++*+================*####+=+===============-------------------------\n"
    "-------------------------------=*****+==============*####+=+==============--------------------------\n"
    "-------------------------------=***##***+=--========*##%%#+=+==============--------------------------\n"
    "-------------------------------=*#*#*******+=---==-=*##%%#+=+==============--------------------------\n"
    "::::::::::---------------------=*#####+=+##***+----=**#%%#==+-=============--------------------------\n"
    ":::::::::::::::::::------------+**#####*+++*##***=-=*##%%#=++--===========---------------------------\n"
    "::::::::::::::::::::::--------=****#*****+*+*+*##****##%%*===----------------------------------------\n"
    "::::::::::::::::::::::::::-:-+*********+*+++++=++****+++*+==-----==+=-------------------------------\n"
    "::::::::::::::::::::::::::::-*#********+++*+=+=+####*****++===++**+=--------------------------------\n"
    ":::::::::::::::::::::::::::-+#####*****+=+*+===+###******#####***=----------------------------------\n"
    "::::::::::::::::::::::::::=*####%%###%%%%#*+*++===+##*********####*+-------------------------------===+\n"
    ":::::::::::::::::::::::::-*######*#%%#%%%%%%%%#*+===*#####*****#####*+==-------------------------==++++=+\n"
    "::::::::::::::::::::::::-+########*#%%%%%%%%%%%%*+==*########+++**#**#%%#*==------------------====+++=====+\n"
    "::::::::::::::::::::::::=***########*%%%%%%%%%%+==+########*++++**+=-=*%%#*+==-----------=================\n"
    "=-:::::::::::::::::::::-****########*+++#*==-+###*+%%@%%%%%%*=+*++-----=#%%#*=-----======================\n"
    "+++++++===--:::::::::::-*###%%#####*+=---===--=****##%%%%%%##**++=--------+#%%#*--=======================\n"
    "+====================--=#####****++======+++=--=*#*+*##*+++**+-------===+*%%%%#+=-====================\n"
    "========================*##*****++====+++*%%%%#*=-=**+*###*+++*+=--==========+*###+===================\n"
    "+=======================*####****++++*****#%%##*=--=-+***+++++=================+###*+================\n"
    "++****++++==+++++=+++===+####*****++*++****%%%%*--:----++++**++*#*+================+###*=-============\n"
    "++++++++++++****+++++++==+****++++++**######++=-----===+++++=*###*+================+*###*===========\n"
    "========+++++++++++++*+==++*+++++**++****####*+===-===---=++-+####**+=================+*###+===+++++\n"
    "==================++++===++++*******++*****++======------==--+#####**+===========+=======+*###+===++\n"
    "==============+===+=++===++++++***********++======-------=--:+**####***+==========++========+*#%%#+==\n"
    "===+===+++=====+=++**+===+++++++*++*******++++=+++==-------:-=+**####**+=========+=++===++=====+*##*\n"
    "===+===++=====++***+++====+++++++++++++*+++++++=====---::-::-++****##***++++=====++++===++++=====++#\n"
    "=++++++=++=++********+====++++++++++++++++++=======---::::::=+*****###*+*++=======++++==+++=========\n"
    "++++++++++*##********+===+++++++++++======++=======--:-::::-*##*****##**+++=======+++++==========+==\n"
    "+++++++*###*#*######*+====++++++++++==++++========------::-+###%%#***###***+=====================++++\n"
    "++***################*=====++++++++====+====+===-----------+###%%%%######****+=====+==========++++++==\n"
    "+*####################+======++++++==============--------:-+*##%%%%%%#####****+=====++++++===++=+++++==\n"
    "######################*=======+++++==========---=---------=**##%%%%########*#*+==+++++++++++++==+++++=\n"
    "#######################+===+++++++++++=======----------::-+####%%%%#######*##*+====+==+++======+=+++++\n"
    "#######################*+==++++++++++++=====-----=-------=*###%%%%%%%%####**###*====++=+++======++++++==\n"
    "########################*++++=+++===+++========---------=+*#%%#%%%%%%#####**###*+===++++++++++==++++++++\n"
    "#########################++++++++++=++++=========------=**####%%%%%%####***####*+==+++++++++===++++++++\n"
    "########################**++++++++++==+++===========---=*####%%%%%%%%###***#####*+==++++++++++++++++++++\n"
    "###########################*+++++++++++==============++*####%%%%%%%%###**+*######*++++++++++++++++++++++\n"
    "##################%%#######%%#*++++==+++=+============++*#####%%%%%%%%#***+*#######*++++++++++++++++++++++\n"
    "################%%########%%@%%%%*++++=+==+++++==++======++*###%%%%%%##***++*#%%%%####*++++++++++++++++++++++\n"
    "################**#######%%%%@%%*+++**+++++++++*+++======+*#%%%%%%%%%%#**++**#%%%%####*+++++++++++++++++++++++\n"
    "##############**##########%%@%%*+++**********++**++===--==+**####*++*#%%%%%%##****+++++++++++++++++++++++\n"
    "###########%%##############%%%%%%*+++***####*#******++===-=======+***##%%%%####***+++++++++++++++++*++++++\n"
    "#########%%#################%%%%*+**######**####*****+===-====+*###%%%%#######*++++++++**++++++++++++*+++\n"
    "#######%%#####################*+*###########%%%%%%####*+======+###%%%%%%%%#####**+++==+++****===+++++****+==\n"
    "*####%%######################**#######*###%%%%%%%%%%%%%%##*+==-=+*##%%%%#####**+++=+=========+=======+**##+==\n"
    "***#%%####################******#**####*######%%%%%%%%###**+==*#####*****+++++++=================+****+==\n"
    "**##*********###########*****+****##*******####%%%%####*==*##*****+++++++++++=========================\n"
    "##**************#####****+++++#***#####*****#####***+==+#*********++++++++==========================\n"
    "*************************+==++****#%%%%############*+++=+**********+++++++++==========================\n"
    "**************************++=+++*#%%%%#############**++=+******++**+**+++++===========================\n"
    "******************+++++++******##################*++===--+***++*++++++++*+==========================\n"
    "***************++++++++++++++++******###########***+==---+**+++++++++++*+++****++===================\n"
    "*+***********++++++++++++++++++++++++****######**+++==---+*+++++++++++++++++++=++***++==============\n"
    "************+++++++++++++++++++++++++++++****##**+==----=++++++++++++++++++++++++++++++*#*++========\n"
    "+++********+++++++++++++++++++++++++++++++***##*+====--=++++++++++++++*++++++++++++++++++++++***++==\n"
    "+++*+*+*++++++++++++++++++++++++++++++++++++******+=++++++++++++++++++++++++++++++++++++++++++++++**\n"
    "+++++++++++++===++++++++++++++++++++++++++++++++++*+++++++++++++++++++++++++++++++++++++++++++++++++\n"
    "++++++++++++===++++=+==+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
    "+++++++++=======++++++++++++++++++++++++++++++++++++++++++++++++++++*+++++++++++++++++++++++++++++++\n"
    "++++++++=======+++++++++++++++++++++++++++++++++++++++++++++++++++++*+++++++++++++++=+++++++++++++++\n"
    "+++++==+=====++++++++++++++++++++++++++++++++++++++++++++++++++++++*++++++++++++=+++++++++++++++++++\n"
    "\n\nYAY! POLTORASHKA!\n\n" );
};

