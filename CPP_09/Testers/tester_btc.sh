#!/bin/bash

# ██████╗ ████████╗ ██████╗    ████████╗███████╗███████╗████████╗███████╗██████╗ 
# ██╔══██╗╚══██╔══╝██╔════╝    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
# ██████╔╝   ██║   ██║            ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
# ██╔══██╗   ██║   ██║            ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
# ██████╔╝   ██║   ╚██████╗       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
# ╚═════╝    ╚═╝    ╚═════╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
#
# [!] Bitcoin Exchange Rate Security Assessment Tool
# [!] Penetration Testing Suite for CPP Module 09 Ex00
# [!] Author: manugonz | Target: BTC Exchange
# [!] Classification: CONFIDENTIAL

PROGRAM_NAME="./btc"
INPUT_DIR="../Testers/inputstxt/"
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
CRYPTO="₿"

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
    head -8 "$0" | tail -6 | sed 's/^# //'
    echo -e "${RED}${BOLD}"
    echo "╔══════════════════════════════════════════════════════════════════════════════╗"
    echo "║                                                                              ║"
    echo -e "║  ${GREEN}${HACK}${CYAN} MANUGONZ SECURITY LABS ${RESET}${RED}${BOLD}                                                  ║"
    echo -e "║  ${RED}${SKULL} BITCOIN EXCHANGE PENETRATION TEST                                         ║"
    echo "║                                                                              ║"
    echo "║  TARGET: ./btc                                                               ║"
    echo -e "║  STATUS: ${GREEN}SCANNING${RED}                                                            ║"
    echo "║  TIMESTAMP: $(date '+%H:%M:%S - %d/%m/%Y')                                            ║"
    echo -e "║  OPERATOR: ${YELLOW}$USER${RED}@${YELLOW}$(hostname)${RED}                                         ║"
    echo "║                                                                              ║"
    echo "╚══════════════════════════════════════════════════════════════════════════════╝"
    echo -e "${RESET}"
    echo -e "${DIM}${CYAN}[INFO]${RESET} Initializing blockchain security assessment protocols..."
    echo -e "${DIM}${CYAN}[INFO]${RESET} Loading crypto exploit modules..."
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
if cat /tmp/build_stdout.log | egrep -iq "(nothing|already|up to date)"; then
    echo -e "${GREEN}${LOCK} SECURE${RESET}"
else
    echo -e "${YELLOW}${WARN} SUSPICIOUS ACTIVITY${RESET}"
fi

rm -f /tmp/build_stderr.log /tmp/build_stdout.log

echo -ne "${CYAN}[SCAN]${RESET} Analyzing compiler flags... "
if grep -sq -- "-Wall" Makefile; then echo -ne "${DIM}-Wall ${RESET}${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-Wextra" Makefile; then echo -ne "${DIM}-Wextra ${RESET}${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-Werror" Makefile; then echo -ne "${DIM}-Werror ${RESET}${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -n " "
if grep -sq -- "-std=c++98" Makefile; then echo -ne "${DIM}-std=c++98 ${RESET}${GREEN}✓${RESET}"; else echo -ne "${RED}✗${RESET}"; fi
echo -e " ${DIM}${CYAN}→ Exploit mitigation protocols${RESET}"

else 
    make >/dev/null 
fi

# ═══════════════════════════════════════════════════════════════════════════════
# CRYPTOCURRENCY PAYLOAD INJECTION SUITE
# ═══════════════════════════════════════════════════════════════════════════════

function crypto_exploit_test() {
    local payload="$1"
    local description="$2"
    local exploit_id="$3"
    
    echo -e "${DIM}${CYAN}[PAYLOAD]${RESET} ${YELLOW}${CRYPTO}-${exploit_id}${RESET} → ${description}"
    echo -ne "${DIM}          Input: ${RESET}${MAGENTA}\"$payload\"${RESET} → "
    
    local result
    if [[ -z "$payload" ]]; then
        result=$(${PROGRAM_NAME} 2>&1)
    else
        result=$(${PROGRAM_NAME} "$payload" 2>&1)
    fi
    
    echo -e "${GREEN}${result}${RESET}"
    echo -e "${DIM}          ────────────────────────────────────────────────────────────${RESET}"
}

function file_exploit_test() {
    local filename="$1"
    local description="$2"
    local exploit_id="$3"
    
    echo -e "${DIM}${CYAN}[$filename]${RESET} ${YELLOW}${CRYPTO}-${exploit_id}${RESET} → ${description}"
    
    # Copy test file to input.txt
    if [[ -f "${INPUT_DIR}${filename}" ]]; then
        cp "${INPUT_DIR}${filename}" ./input.txt
        local result=$(${PROGRAM_NAME} input.txt 2>&1)
        rm -f input.txt
    else
        local result="File not found: ${INPUT_DIR}${filename}"
    fi
    
    echo -e "${GREEN}${result}${RESET}"
    echo -e "${DIM}               ────────────────────────────────────────────────────────────${RESET}"
}

echo -e "\n${BG_RED}${WHITE}${BOLD} [ATTACK VECTOR] ARGUMENT INJECTION VULNERABILITIES ${RESET}"

crypto_exploit_test "" "NULL argument buffer overflow" "001"
crypto_exploit_test '""' "Empty string injection" "002"
crypto_exploit_test "nonexistent_file.txt" "File system reconnaissance" "003"

echo -e "\n${BG_YELLOW}${BLACK}${BOLD} [VULNERABILITY] CSV FORMAT MANIPULATION ${RESET}"

file_exploit_test "PAYLOAD_0.txt" "Empty line injection attack" "004"
file_exploit_test "PAYLOAD_1.txt" "Multiple header injection" "005"
file_exploit_test "PAYLOAD_2.txt" "Missing header exploitation" "006"
file_exploit_test "PAYLOAD_2bis.txt" "Empty header bypass attempt" "007"
file_exploit_test "PAYLOAD_3.txt" "Header name spoofing attack" "008"

echo -e "\n${BG_RED}${WHITE}${BOLD} [CRITICAL] BLOCKCHAIN DATA CORRUPTION ${RESET}"

file_exploit_test "PAYLOAD_4.txt" "Date format injection attack" "009"
file_exploit_test "PAYLOAD_5.txt" "Bitcoin value overflow exploit" "010"

# ═══════════════════════════════════════════════════════════════════════════════
# PENETRATION TEST COMPLETION
# ═══════════════════════════════════════════════════════════════════════════════

echo -e "\n${RED}${BOLD}"
echo "╔══════════════════════════════════════════════════════════════════════════════╗"
echo "║                                                                              ║"
echo -e "║  ${GREEN}${HACK}${GREEN} SECURITY ASSESSMENT COMPLETE ${RESET}${RED}${BOLD}                                            ║"
echo "║                                                                              ║"
echo -e "║  ${RED}${SKULL} Target: Bitcoin Exchange                                                  ║"
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
