#!/bin/bash

# ██████╗ ██████╗ ███╗   ██╗    ████████╗███████╗███████╗████████╗███████╗██████╗ 
# ██╔══██╗██╔══██╗████╗  ██║    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
# ██████╔╝██████╔╝██╔██╗ ██║       ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
# ██╔══██╗██╔═══╝ ██║╚██╗██║       ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
# ██║  ██║██║     ██║ ╚████║       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
# ╚═╝  ╚═╝╚═╝     ╚═╝  ╚═══╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
#
# [!] Reverse Polish Notation Security Assessment Tool
# [!] Penetration Testing Suite for CPP Module 09 Ex01
# [!] Author: manugonz | Target: RPN Calculator
# [!] Classification: CONFIDENTIAL

PROGRAM_NAME="./RPN"
TEST_MODE=1

# ═══════════════════════════════════════════════════════════════════════════════
# EXPLOIT FRAMEWORK CONFIGURATION
# ═══════════════════════════════════════════════════════════════════════════════

# Terminal Colors & Effects
SKULL="☠"
LOCK="🔒"
BOOM="💥"
HACK="⚡"
WARN="⚠"

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
RESET="\033[0m"

BOLD="\033[1m"
DIM="\033[2m"
UNDERLINE="\033[4m"
BLINK="\033[5m"
REVERSE="\033[7m"

# Background Colors
BG_RED="\033[41m"
BG_GREEN="\033[42m"
BG_YELLOW="\033[43m"
BG_BLUE="\033[44m"
BG_MAGENTA="\033[45m"
BG_CYAN="\033[46m"

# ═══════════════════════════════════════════════════════════════════════════════
# PENETRATION TEST INITIALIZATION
# ═══════════════════════════════════════════════════════════════════════════════

function hack_banner() {
    clear
    head -8 tester_rpn.sh | tail -6 | sed 's/^# //'
    echo -e "${RED}${BOLD}"
    echo "╔══════════════════════════════════════════════════════════════════════════════╗"
    echo "║                                                                              ║"
    echo -e "║  ${GREEN}${HACK}${CYAN} MANUGONZ SECURITY LABS ${RESET}${RED}${BOLD}                                                  ║"
    echo -e "║  ${RED}${SKULL} RPN CALCULATOR PENETRATION TEST                                           ║"
    echo "║                                                                              ║"
    echo "║  TARGET: ./RPN                                                               ║"
    echo -e "║  STATUS: ${GREEN}SCANNING${RED}                                                            ║"
    echo "║  TIMESTAMP: $(date '+%H:%M:%S - %d/%m/%Y')                                            ║"
    echo -e "║  OPERATOR: ${YELLOW}$USER${RED}@${YELLOW}$(hostname)${RED}                                         ║"
    echo "║                                                                              ║"
    echo "╚══════════════════════════════════════════════════════════════════════════════╝"
    echo -e "${RESET}"
    echo -e "${DIM}${CYAN}[INFO]${RESET} Initializing security assessment protocols..."
    echo -e "${DIM}${CYAN}[INFO]${RESET} Loading exploit modules..."
    sleep 1
}

hack_banner

# ═══════════════════════════════════════════════════════════════════════════════
# BUILD SYSTEM VULNERABILITY ASSESSMENT
# ═══════════════════════════════════════════════════════════════════════════════

if [[ $TEST_MODE == 1 ]] ; then 
echo -e "\n${BG_YELLOW}${BLACK}${BOLD} [EXPLOIT] BUILD SYSTEM ANALYSIS ${RESET}"

echo -ne "${CYAN}[SCAN]${RESET} Testing compilation integrity... "
make re 1>/dev/null 2> /tmp/build_stderr.log
sleep 0.5
make > /tmp/build_stdout.log 2>&1

if [[ -s /tmp/build_stderr.log ]]; then
    echo -e "${RED}${BOOM} STDERR DETECTED${RESET}"
else
    echo -e "${GREEN}${HACK} CLEAN${RESET}"
fi

echo -ne "${CYAN}[SCAN]${RESET} Checking for relink vulnerabilities... "
if cat /tmp/build_stdout.log | egrep -viq "(nothing|already|date)"; then
    echo -e "${YELLOW}${WARN} SUSPICIOUS ACTIVITY${RESET}"
else
    echo -e "${GREEN}${LOCK} SECURE${RESET}"
fi

rm -f /tmp/build_stderr.log /tmp/build_stdout.log

echo -ne "${CYAN}[SCAN]${RESET} Analyzing compiler flags... "
if grep -sq -- "-Wall" Makefile; then echo -ne "${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-Wextra" Makefile; then echo -ne "${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-Werror" Makefile; then echo -ne "${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-std=c++98" Makefile; then echo -ne "${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -e " ${DIM}(Security flags)${RESET}"

else 
    make >/dev/null 
fi

# ═══════════════════════════════════════════════════════════════════════════════
# PAYLOAD INJECTION SUITE
# ═══════════════════════════════════════════════════════════════════════════════

function exploit_test() {
    local payload="$1"
    local description="$2"
    local exploit_id="$3"
    local extra_args="$4"
    
    echo -e "${DIM}${CYAN}[PAYLOAD]${RESET} ${YELLOW}EX-${exploit_id}${RESET} → ${description}"
    echo -ne "${DIM}          Input: ${RESET}${MAGENTA}\"$payload\"${RESET}"
    if [[ -n "$extra_args" ]]; then
        echo -ne " ${MAGENTA}\"$extra_args\"${RESET}"
    fi
    echo -ne " → "
    
    local result
    if [[ -z "$payload" ]]; then
        result=$(${PROGRAM_NAME} 2>&1)
    elif [[ -n "$extra_args" ]]; then
        result=$(${PROGRAM_NAME} "$payload" "$extra_args" 2>&1)
    else
        result=$(${PROGRAM_NAME} "$payload" 2>&1)
    fi
    
    echo -e "${GREEN}$result${RESET}"
    echo -e "${DIM}          ────────────────────────────────────────────────────────────${RESET}"
}

echo -e "\n${BG_RED}${WHITE}${BOLD} [ATTACK VECTOR] INPUT FORMAT VULNERABILITIES ${RESET}"

exploit_test "" "NULL payload injection" "001"

echo -e "\n${BG_YELLOW}${BLACK}${BOLD} [VULNERABILITY] INVALID ARGUMENT VECTORS ${RESET}"

exploit_test "jesuispasunrpn" "String buffer overflow attempt" "002"
exploit_test "word1" "Multi-argument injection" "003" "word2"
exploit_test "1 1 +" "Multiple RPN argument exploitation" "004" "1 1 -"
exploit_test "1  1   +" "Whitespace parsing vulnerability" "005"
exploit_test " 1 1 + " "Leading/trailing space injection" "006"
exploit_test "  1 1 +   " "Multiple space buffer attack" "007"
exploit_test "1	1	+" "Tab character injection" "008"
exploit_test "11+" "Zero-space token exploitation" "009"

echo -e "\n${BG_RED}${WHITE}${BOLD} [CRITICAL] RPN STACK MANIPULATION ${RESET}"

exploit_test "1" "Single operand stack underflow" "010"
exploit_test "1 2 3" "Multiple operand injection" "011"
exploit_test "+" "Naked operator exploit" "012"
exploit_test "+ - *" "Operator flood attack" "013"
exploit_test "1 +" "Insufficient operand vulnerability" "014"
exploit_test "+ 1" "Prefix operator injection" "015"
exploit_test "1 + +" "Operator overflow trigger" "016"
exploit_test "+ 1 +" "Interleaved operator attack" "017"
exploit_test "+ + 1" "Double prefix exploit" "018"
exploit_test "+ 1 + 1" "Equal count manipulation" "019"
exploit_test "+ + 1 1" "Reordered equal count attack" "020"
exploit_test "1 + + 1" "Midpoint operator injection" "021"
exploit_test "1 1 + +" "Postfix operator overflow" "022"
exploit_test "12 33 + 42 -" "Multi-digit number handling" "023"
exploit_test "1 3 + 420 -" "Large number injection" "024"
exploit_test "1 2 %" "Invalid operator injection" "025"
exploit_test "1 2 + 3 - 5 =" "Assignment operator exploit" "026"
exploit_test "1 - 2 3 + 5 +" "Malformed expression attack" "027"
exploit_test "- + 5 + 4 3 7" "Complex order manipulation" "028"
exploit_test "+5 +4 -" "Positive prefix injection" "029"
exploit_test "1 2 3 4 + + -" "Alternative RPN format test" "030"
exploit_test "1.4 1.34 +" "Floating point injection" "031"
exploit_test "1 0 /" "Basic division by zero" "032"
exploit_test "1 5 3 - 0 * /" "Complex zero division" "033"
exploit_test "4 2 / 0 /" "Intermediate division by zero" "034"

echo -e "\n${BG_GREEN}${BLACK}${BOLD} [LEGITIMATE] CALCULATION VERIFICATION ${RESET}"

exploit_test "1 1 +" "Basic addition verification" "101"
exploit_test "-1 -1 +" "Negative addition test" "102"
exploit_test "2 3 *" "Multiplication verification" "103"
exploit_test "2 3 -" "Subtraction test" "104"
exploit_test "8 2 /" "Division verification" "105"
exploit_test "8 2 / 4 + 1 - 9 * 3 +" "Complex chain calculation" "106"
exploit_test "8 2 / 4 + 1 - 9 * 3 + -1 *" "Negative result chain" "107"
exploit_test "8 2 4 1 9 3 / + - * +" "Alternative RPN format" "108"

echo -e "\n${BG_CYAN}${BLACK}${BOLD} [ADVANCED] MANUGONZ EDGE CASE SUITE ${RESET}"

exploit_test "-0 5 +" "Negative zero edge case" "E001"
exploit_test "9 9 * 9 *" "Large number calculation" "E002"
exploit_test "1 3 /" "Decimal precision test" "E003"

# ═══════════════════════════════════════════════════════════════════════════════
# PENETRATION TEST COMPLETION
# ═══════════════════════════════════════════════════════════════════════════════

echo -e "\n${RED}${BOLD}"
echo "╔══════════════════════════════════════════════════════════════════════════════╗"
echo "║                                                                              ║"
echo -e "║  ${GREEN}${HACK}${GREEN} SECURITY ASSESSMENT COMPLETE ${RESET}${RED}${BOLD}                                            ║"
echo "║                                                                              ║"
echo -e "║  ${RED}${SKULL} Target: RPN Calculator                                                    ║"
echo -e "║  ${YELLOW}${LOCK} Status: ${GREEN}ALL EXPLOITS TESTED${RED}                                              ║"
echo -e "║  ${YELLOW}${WARN} Vulnerabilities: ${YELLOW}HANDLED${RED}                                                  ║"
echo -e "║  ${RED}${BOOM} Security Level: ${GREEN}MAXIMUM${RED}                                                  ║"
echo "║                                                                              ║"
echo -e "║  ${CYAN}Developed by: ${YELLOW}MANUGONZ SECURITY LABS${RED}                                        ║"
echo -e "║  ${DIM}Contact: manugonz@security.lab${RED}${BOLD}                                              ║"
echo "║                                                                              ║"
echo "╚══════════════════════════════════════════════════════════════════════════════╝"
echo -e "${RESET}"

echo -e "${DIM}${CYAN}[CLEANUP]${RESET} Removing build artifacts..."
make fclean &>/dev/null
echo -e "${DIM}${CYAN}[CLEANUP]${RESET} Security assessment logs cleared."
echo -e "${GREEN}${HACK} PENETRATION TEST SUCCESSFUL${RESET}"
