#!/bin/bash

# ██████╗ ███╗   ███╗███████╗██████╗  ██████╗ ███████╗    ████████╗███████╗███████╗████████╗███████╗██████╗ 
# ██╔══██╗████╗ ████║██╔════╝██╔══██╗██╔════╝ ██╔════╝    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
# ██████╔╝██╔████╔██║█████╗  ██████╔╝██║  ███╗█████╗         ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
# ██╔═══╝ ██║╚██╔╝██║██╔══╝  ██╔══██╗██║   ██║██╔══╝         ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
# ██║     ██║ ╚═╝ ██║███████╗██║  ██║╚██████╔╝███████╗       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
# ╚═╝     ╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
#
# [!] Ford-Johnson Algorithm Security Assessment Tool
# [!] Penetration Testing Suite for CPP Module 09 Ex02
# [!] Author: manugonz | Target: PmergeMe Algorithm
# [!] Classification: CONFIDENTIAL

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

# Compatibility Symbols
CHECK="✅"
CROSS="❌"
ROCKET="🚀"
GEAR="⚙"

PROGRAM_NAME="./PmergeMe"
total_tests=0
passed_tests=0
failed_tests=()

# ═══════════════════════════════════════════════════════════════════════════════
# PENETRATION TEST INITIALIZATION
# ═══════════════════════════════════════════════════════════════════════════════

function hack_banner() {
    clear
    head -8 tester.sh | tail -6 | sed 's/^# //'
    echo -e "${RED}${BOLD}"
    echo "╔══════════════════════════════════════════════════════════════════════════════╗"
    echo "║                                                                              ║"
    echo -e "║  ${GREEN}${HACK}${CYAN} MANUGONZ SECURITY LABS ${RESET}${RED}${BOLD}                                                  ║"
    echo -e "║  ${RED}${SKULL} PMERGE-ME COMPREHENSIVE TESTING SUITE ${RESET}${RED}${BOLD}                                    ║"
    echo "║                                                                              ║"
    echo "║  TARGET: ./PmergeMe                                                          ║"
    echo -e "║  STATUS: ${GREEN}FULL SYSTEM ASSESSMENT${RED}                                              ║"
    echo "║  TIMESTAMP: $(date '+%H:%M:%S - %d/%m/%Y')                                            ║"
    echo -e "║  OPERATOR: ${YELLOW}$USER${RED}@${YELLOW}$(hostname)${RED}                                         ║"
    echo "║                                                                              ║"
    echo "╚══════════════════════════════════════════════════════════════════════════════╝"
    echo -e "${RESET}"
    echo -e "${DIM}${CYAN}[INFO]${RESET} Initializing Ford-Johnson algorithm assessment..."
    echo -e "${DIM}${CYAN}[INFO]${RESET} Loading sorting exploit modules..."
    echo -e "${GREEN}${LOCK}${RESET} Target acquired. Beginning comprehensive test..."
}

hack_banner

# ═══════════════════════════════════════════════════════════════════════════════
# SECURITY ASSESSMENT FUNCTIONS
# ═══════════════════════════════════════════════════════════════════════════════

# Function to print section headers
section_header() {
    echo ""
    echo -e "${BG_YELLOW}${BLACK}${BOLD} ${HACK} $1 ${RESET}"
}
run_test() {
    local test_name="$1"
    local command="$2"
    local expect_success="$3"
    
    ((total_tests++))
    
    echo -e "${DIM}${YELLOW}[TEST]${RESET} $test_name"
    
    if [ "$expect_success" = "true" ]; then
        echo -e "${DIM}${GREEN}[EXP]${RESET}  SUCCESS"
        echo -e "${DIM}${BLUE}[CMD]${RESET}  $command"
        if eval "$command" ; then
            echo -e "${DIM}${GREEN}[RES]${RESET}  ${CHECK} PASS - Algorithm executed successfully\n"
            ((passed_tests++))
            return 0
        else
            echo -e "${DIM}${RED}[RES]${RESET}  ${CROSS} FAIL - Algorithm failed to execute\n"
            echo -e "${RED}${BOLD}[FAILED TEST]${RESET} $test_name"
            echo -e "${RED}Command output:${RESET}"
            eval "$command" 2>&1
            failed_tests+=("$test_name")
            return 1
        fi
    else
        echo -e "${DIM}${RED}[EXP]${RESET}  ERROR"
        echo -e "${DIM}${BLUE}[CMD]${RESET}  $command"
        if eval "$command" 2>&1; then
            echo -e "${DIM}${RED}[RES]${RESET}  ${CROSS} FAIL - Should have failed but succeeded\n"
            echo -e "${RED}${BOLD}[FAILED TEST]${RESET} $test_name"
            echo -e "${RED}This command should have failed but succeeded:${RESET}"
            eval "$command" 2>&1
            failed_tests+=("$test_name")
            return 1
        else
            echo -e "${DIM}${GREEN}[RES]${RESET}  ${CHECK} PASS - Input correctly rejected\n"
            ((passed_tests++))
            return 0
        fi
    fi
}

# Function to run performance test
run_performance_test() {
    local test_name="$1"
    local display_command="$2"
    local actual_command="$3"
    
    # If only 2 parameters, use the same command for display and execution
    if [ -z "$actual_command" ]; then
        actual_command="$display_command"
    fi
    
    echo -e "${DIM}${YELLOW}[PERF]${RESET} $test_name"
    echo -e "${DIM}${BLUE}[CMD]${RESET}  $display_command"
    echo -e "${DIM}${CYAN}[OUT]${RESET}"
    echo ""
    
    # Execute command and capture exit code
    if eval "$actual_command"; then
        echo ""
        echo -e "${DIM}${GREEN}[RES]${RESET}  ${CHECK} PASS - Performance test executed successfully"
        echo -e "${ROCKET} Performance test completed"
        echo ""
        return 0
    else
        echo ""
        echo -e "${DIM}${RED}[RES]${RESET}  ${CROSS} FAIL - Performance test failed to execute"
        echo -e "${RED}${BOLD}[FAILED PERFORMANCE TEST]${RESET} $test_name"
        failed_tests+=("$test_name")
        echo ""
        return 1
    fi
}

# ═══════════════════════════════════════════════════════════════════════════════
# COMPILATION & MAKEFILE VERIFICATION
# ═══════════════════════════════════════════════════════════════════════════════

section_header "COMPILATION & MAKEFILE VERIFICATION"

echo -e "${YELLOW}${BOLD}${GEAR} Checking compilation environment...${RESET}"
echo ""

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

# Compile the program
echo -e "${YELLOW}${BOLD}Compiling target...${RESET}"
if make > /dev/null 2>&1; then
    echo -e "${CHECK} Compilation successful"
else
    echo -e "${CROSS} Compilation failed"
    exit 1
fi

# Check if executable exists
if [ -f "$PROGRAM_NAME" ]; then
    echo -e "${CHECK} Executable created successfully"
else
    echo -e "${CROSS} Executable not found"
    exit 1
fi

echo ""

# ═══════════════════════════════════════════════════════════════════════════════
# BASIC FUNCTIONALITY EXPLOITS
# ═══════════════════════════════════════════════════════════════════════════════

section_header "BASIC FUNCTIONALITY EXPLOITS"

run_test "Single element payload" "$PROGRAM_NAME 42" "true"

run_test "Multiple element payload" "$PROGRAM_NAME 42 21 84" "true"

run_test "Sequential ordering attack" "$PROGRAM_NAME 1 2 3 4 5" "true"

run_test "Reverse ordering attack" "$PROGRAM_NAME 5 4 3 2 1" "true"

run_test "Duplicate element injection" "$PROGRAM_NAME 42 21 42 21" "true"

run_test "Zero boundary exploit" "$PROGRAM_NAME 0" "true"

run_test "Positive sign injection" "$PROGRAM_NAME +42" "true"

run_test "Integer maximum boundary" "$PROGRAM_NAME 2147483647" "true"

run_test "Large number stress test" "$PROGRAM_NAME 1000000000" "true"

# ═══════════════════════════════════════════════════════════════════════════════
# INPUT VALIDATION BYPASSES
# ═══════════════════════════════════════════════════════════════════════════════

section_header "INPUT VALIDATION BYPASSES"

run_test "Empty argument vector" "$PROGRAM_NAME" "false"

run_test "Negative integer injection" "$PROGRAM_NAME -42" "false"

run_test "Mixed sign payload" "$PROGRAM_NAME 42 -21" "false"

run_test "Alphabetic character injection" "$PROGRAM_NAME abc" "false"

run_test "Alphanumeric hybrid attack" "$PROGRAM_NAME 42abc" "false"

run_test "Floating point injection" "$PROGRAM_NAME 4.2" "false"

run_test "Integer overflow exploit" "$PROGRAM_NAME 2147483648" "false"

run_test "Extreme overflow payload" "$PROGRAM_NAME 999999999999" "false"

run_test "Double sign manipulation" "$PROGRAM_NAME ++42" "false"

run_test "Sign-only payload" "$PROGRAM_NAME +" "false"

# ═══════════════════════════════════════════════════════════════════════════════
# ADVANCED PARSING ATTACKS
# ═══════════════════════════════════════════════════════════════════════════════

section_header "ADVANCED PARSING ATTACKS"

run_test "Leading zeros exploit" "$PROGRAM_NAME 0000042" "true"

run_test "Octal notation attempt" "$PROGRAM_NAME 007" "true"

run_test "Hexadecimal injection" "$PROGRAM_NAME 0x42" "false"

run_test "Scientific notation attack" "$PROGRAM_NAME 1e3" "false"

# ═══════════════════════════════════════════════════════════════════════════════
# CRITICAL EDGE CASES (DEMO FOUND TESTS)
# ═══════════════════════════════════════════════════════════════════════════════

section_header "CRITICAL EDGE CASES (DEMO FOUND TESTS)"

run_test "Empty string injection" '$PROGRAM_NAME ""' "false"

run_test "Whitespace-only payload" '$PROGRAM_NAME "   "' "false"

run_test "Tab character injection" '$PROGRAM_NAME "\t"' "false"

run_test "Newline character injection" '$PROGRAM_NAME "\n"' "false"

run_test "Mixed spaces and tabs" '$PROGRAM_NAME "  \t  "' "false"

run_test "Leading/trailing whitespace" '$PROGRAM_NAME "  123  "' "true"

run_test "Number with internal space" '$PROGRAM_NAME "12 3"' "true"

run_test "Decimal with comma" '$PROGRAM_NAME "12,3"' "false"

run_test "Multiple decimal points" '$PROGRAM_NAME "1.2.3"' "false"

run_test "Letter after number" '$PROGRAM_NAME "123a"' "false"

run_test "Letter before number" '$PROGRAM_NAME "a123"' "false"

run_test "Mixed alphanumeric backwards" '$PROGRAM_NAME "9abc8"' "false"

run_test "Zero with letter suffix" '$PROGRAM_NAME "0a"' "false"

run_test "Plus sign with letter" '$PROGRAM_NAME "+a"' "false"

run_test "Negative zero attempt" '$PROGRAM_NAME "-0"' "false"

run_test "Multiple plus signs" '$PROGRAM_NAME "+++123"' "false"

run_test "Mixed signs sequence" '$PROGRAM_NAME "+-+123"' "false"

run_test "Parentheses injection" '$PROGRAM_NAME "(123)"' "false"

run_test "Bracket injection" '$PROGRAM_NAME "[123]"' "false"

run_test "Underscore injection" '$PROGRAM_NAME "1_23"' "false"

run_test "Apostrophe injection" '$PROGRAM_NAME "1'\''23"' "false"

run_test "Unicode digit attempt" '$PROGRAM_NAME "１２３"' "false"

run_test "Binary notation attempt" '$PROGRAM_NAME "0b1010"' "false"

run_test "Octal prefix attempt" '$PROGRAM_NAME "0o123"' "false"

run_test "Long with L suffix" '$PROGRAM_NAME "123L"' "false"

run_test "Unsigned suffix attempt" '$PROGRAM_NAME "123U"' "false"

run_test "Float suffix attempt" '$PROGRAM_NAME "123f"' "false"

run_test "Double suffix attempt" '$PROGRAM_NAME "123d"' "false"

run_test "Hash symbol injection" '$PROGRAM_NAME "#123"' "false"

run_test "Dollar sign injection" '$PROGRAM_NAME "$123"' "false"

run_test "Percent sign injection" '$PROGRAM_NAME "%123"' "false"

run_test "Extreme leading zeros" '$PROGRAM_NAME "000000000000000000000000000000042"' "true"

run_test "Single character non-digit" '$PROGRAM_NAME "a"' "false"

run_test "Single character digit" '$PROGRAM_NAME "5"' "true"

run_test "Empty after valid number" '$PROGRAM_NAME 123 ""' "false"

run_test "Spaces after valid number" '$PROGRAM_NAME 123 "   "' "false"

# ═══════════════════════════════════════════════════════════════════════════════
# PERFORMANCE & SCALABILITY ASSESSMENT
# ═══════════════════════════════════════════════════════════════════════════════

section_header "PERFORMANCE & SCALABILITY ASSESSMENT"

echo -e "${YELLOW}${BOLD}${ROCKET} Executing 42 School Correction Performance Tests${RESET}"
echo ""

# Small scale performance
run_performance_test "Small Scale Algorithm Test (5 elements)" "$PROGRAM_NAME 5 2 8 1 9"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# Medium scale performance  
run_performance_test "Medium Scale Algorithm Test (10 elements)" "$PROGRAM_NAME 9 8 7 6 5 4 3 2 1 0"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# Large scale performance tests - 42 School Correction Sheet Standards
echo -e "${CYAN}${BOLD}Generating large datasets for stress testing...${RESET}"

# 100 elements test (Standard correction)
large_seq_100=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
run_performance_test "Large Scale Test - 100 Elements" "$PROGRAM_NAME \$(shuf -i 1-500 -n 100 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_100"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# 500 elements test (Advanced correction)
large_seq_500=$(shuf -i 1-2500 -n 500 | tr '\n' ' ')
run_performance_test "Extreme Scale Test - 500 Elements" "$PROGRAM_NAME \$(shuf -i 1-2500 -n 500 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_500"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# 1000 elements test (Professional correction)
large_seq_1000=$(shuf -i 1-5000 -n 1000 | tr '\n' ' ')
run_performance_test "Maximum Scale Test - 1000 Elements" "$PROGRAM_NAME \$(shuf -i 1-5000 -n 1000 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_1000"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# 3000 elements test (42 School Official Correction Sheet)
large_seq_3000=$(shuf -i 1-5000 -n 3000 | tr '\n' ' ')
run_performance_test "Ultra Scale Test - 3000 Elements (42 Correction Sheet)" "$PROGRAM_NAME \$(shuf -i 1-5000 -n 3000 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_3000"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# 5000 elements test (Stress test beyond requirements)
large_seq_5000=$(shuf -i 1-10000 -n 5000 | tr '\n' ' ')
run_performance_test "Mega Scale Test - 5000 Elements" "$PROGRAM_NAME \$(shuf -i 1-10000 -n 5000 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_5000"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# 30000 elements test (Stress test beyond requirements)
large_seq_30000=$(shuf -i 1-10000 -n 30000 | tr '\n' ' ')
run_performance_test "Mega Scale Test - 30000 Elements" "$PROGRAM_NAME \$(shuf -i 1-10000 -n 30000 | tr '\\n' ' ')" "$PROGRAM_NAME $large_seq_30000"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))

# Worst case scenario
reverse_seq_100=$(seq 100 -1 1 | tr '\n' ' ')
run_performance_test "Worst Case Scenario - 100 Reverse Sorted" "$PROGRAM_NAME $reverse_seq_100"
((total_tests++)); [ $? -eq 0 ] && ((passed_tests++))


# ═══════════════════════════════════════════════════════════════════════════════
# SECURITY ASSESSMENT REPORT
# ═══════════════════════════════════════════════════════════════════════════════

section_header "SECURITY ASSESSMENT REPORT"

success_rate=$((passed_tests * 100 / total_tests))

echo -e "${BOLD}${CYAN}ASSESSMENT SUMMARY:${RESET}"
echo -e "${DIM}${CYAN}[STAT]${RESET} Total security tests executed: $total_tests"
echo -e "${DIM}${CYAN}[STAT]${RESET} Tests passed: $passed_tests"
echo -e "${DIM}${CYAN}[STAT]${RESET} Tests failed: $((total_tests - passed_tests))"
echo -e "${DIM}${CYAN}[STAT]${RESET} Success rate: $success_rate%"
echo ""

# Show failed tests if any
if [ ${#failed_tests[@]} -gt 0 ]; then
    echo -e "${RED}${BOLD}FAILED TESTS:${RESET}"
    for failed_test in "${failed_tests[@]}"; do
        echo -e "${RED}  ${CROSS} $failed_test${RESET}"
    done
    echo ""
fi

if [ $success_rate -ge 95 ]; then
    echo -e "${GREEN}${BOLD}${LOCK} SECURITY STATUS: MAXIMUM SECURITY${RESET}"
    echo -e "${GREEN}${BOLD}${ROCKET} Your PmergeMe implementation is bulletproof!${RESET}"
    echo -e "${GREEN}${BOLD}${HACK} Ready for 42 School evaluation with maximum confidence!${RESET}"
elif [ $success_rate -ge 85 ]; then
    echo -e "${YELLOW}${BOLD}${WARN} SECURITY STATUS: HIGH SECURITY${RESET}"
    echo -e "${YELLOW}${BOLD}Minor vulnerabilities detected but acceptable for 42${RESET}"
else
    echo -e "${RED}${BOLD}${SKULL} SECURITY STATUS: CRITICAL VULNERABILITIES${RESET}"
    echo -e "${RED}${BOLD}Major security flaws detected - immediate action required${RESET}"
fi

echo ""
echo -e "${RED}${BOLD}"
echo "╔══════════════════════════════════════════════════════════════════════════════╗"
echo "║                                                                              ║"
echo -e "║  ${GREEN}${HACK}${GREEN} SECURITY ASSESSMENT COMPLETE ${RESET}${RED}${BOLD}                                            ║"
echo "║                                                                              ║"
echo -e "║  ${RED}${SKULL} Target: PmergeMe Algorithm                                                ║"
echo -e "║  ${YELLOW}${LOCK} Status: ${GREEN}ALL EXPLOITS TESTED${RED}                                              ║"
echo -e "║  ${YELLOW}${WARN} Vulnerabilities: ${YELLOW}HANDLED${RED}                                                  ║"
echo -e "║  ${RED}${BOOM} Security Level: ${GREEN}MAXIMUM${RED}                                                  ║"
echo "║                                                                              ║"
echo -e "║  ${CYAN}Developed by: ${YELLOW}MANUGONZ SECURITY LABS${RED}                                        ║"
echo -e "║  ${DIM}Contact: manugonz@security.lab${RED}${BOLD}                                              ║"
echo "║                                                                              ║"
echo "╚══════════════════════════════════════════════════════════════════════════════╝"
echo -e "${RESET}"
echo ""
echo -e "${DIM}${CYAN}[CLEANUP]${RESET} Removing build artifacts..."
make fclean &>/dev/null
echo -e "${DIM}${CYAN}[CLEANUP]${RESET} Security assessment logs cleared."
echo -e "${GREEN}${HACK} PENETRATION TEST SUCCESSFUL${RESET}"
