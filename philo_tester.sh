#!/bin/bash
# ============================================================
# 42 PHILOSOPHERS COMPLETE TESTER
# Author: Allan Rabelo
# ============================================================

# --- Default configuration ---
PHILO_EXEC="./philo"
TIMEOUT=10
VERBOSE=0
RUN_STRESS=1

# --- Colors ---
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
CYAN="\033[1;36m"
RESET="\033[0m"

# --- Parse flags ---
while [[ $# -gt 0 ]]; do
	case $1 in
		-v) VERBOSE=1 ;;
		-s) RUN_STRESS=0 ;;
		-f) PHILO_EXEC="$2"; shift ;;
		-t) TIMEOUT="$2"; shift ;;
		*) echo "Unknown flag: $1"; exit 1 ;;
	esac
	shift
done

if [ ! -f "$PHILO_EXEC" ]; then
	echo -e "${RED}Error: binary not found at $PHILO_EXEC${RESET}"
	exit 1
fi

# --- Helper: run test ---
run_test() {
	desc=$1
	cmd=$2
	expect_die=$3
	expect_exit=$4

	echo -e "\n${CYAN}▶️  Test: $desc${RESET}"
	echo -e "Command: $cmd"

	output=$(timeout $TIMEOUT $cmd)
	status=$?

	died=$(echo "$output" | grep -E "died")
	invalid=$(echo "$output" | grep -vE "^[0-9]+ [0-9]+ (has taken a fork|is eating|is sleeping|is thinking|died)")

	# --- Check death expectation ---
	if [[ $expect_die == "yes" && -z "$died" ]]; then
		echo -e "${RED}❌ Expected death, but no philosopher died${RESET}"
	elif [[ $expect_die == "no" && ! -z "$died" ]]; then
		echo -e "${RED}❌ Unexpected death detected${RESET}"
	elif [[ $expect_die == "yes" && ! -z "$died" ]]; then
		echo -e "${GREEN}✅ Death detected as expected${RESET}"
	else
		echo -e "${GREEN}✅ No philosopher died (as expected)${RESET}"
	fi

	# --- Exit behavior ---
	if [[ $expect_exit == "exit" && $status -ne 0 ]]; then
		echo -e "${RED}❌ Program did not exit normally${RESET}"
	elif [[ $expect_exit == "noexit" && $status -eq 0 ]]; then
		echo -e "${YELLOW}⚠️  Program exited but was expected to keep running${RESET}"
	else
		echo -e "${GREEN}✅ Exit behavior is correct${RESET}"
	fi

	# --- Timestamp check ---
	last_time=0
	while read -r line; do
		time=$(echo "$line" | awk '{print $1}')
		if [[ "$time" =~ ^[0-9]+$ && $time -lt $last_time ]]; then
			echo -e "${RED}❌ Timestamp out of order at line:${RESET} $line"
			return
		fi
		last_time=$time
	done <<< "$output"
	echo -e "${GREEN}✅ Timestamps are strictly increasing${RESET}"

	# --- Invalid lines ---
	if [[ ! -z "$invalid" ]]; then
		echo -e "${RED}❌ Invalid output detected:${RESET}"
		echo "$invalid"
	else
		echo -e "${GREEN}✅ All output lines have valid format${RESET}"
	fi

	# --- Verbose output ---
	if [[ $VERBOSE -eq 1 ]]; then
		echo -e "${YELLOW}--- Sample output ---${RESET}"
		echo "$output" | head -n 20
	else
		echo -e "${YELLOW}--- Output sample (first 5 lines) ---${RESET}"
		echo "$output" | head -n 5
	fi
}

# --- Start tests ---
echo -e "${YELLOW}=============================="
echo -e "     PHILOSOPHERS TESTER"
echo -e "==============================${RESET}"

run_test "1 philosopher must die" "$PHILO_EXEC 1 800 200 200" yes exit
run_test "5 philosophers, enough time (no one dies)" "$PHILO_EXEC 5 800 200 200" no noexit
run_test "4 philosophers, short death time (expected death)" "$PHILO_EXEC 4 310 200 100" yes exit
run_test "5 philosophers, must eat 7 times then exit" "$PHILO_EXEC 5 800 200 200 7" no exit
run_test "Edge case: tight timing (possible starvation)" "$PHILO_EXEC 3 600 200 100" yes exit

if [[ $RUN_STRESS -eq 1 ]]; then
	run_test "Stress test: 200 philosophers" "$PHILO_EXEC 200 410 200 200" no noexit
	run_test "Stress test: 199 philosophers" "$PHILO_EXEC 199 610 200 200" no noexit
fi

# --- Bonus: check time-to-die precision ---
echo -e "\n${CYAN}⏱️  Checking death timing precision...${RESET}"
cmd="$PHILO_EXEC 1 500 200 200"
output=$(timeout $TIMEOUT $cmd)
death_time=$(echo "$output" | grep "died" | awk '{print $1}')
if [[ -z "$death_time" ]]; then
	echo -e "${RED}❌ No death line found (expected at ~500ms)${RESET}"
else
	if (( death_time > 450 && death_time < 550 )); then
		echo -e "${GREEN}✅ Death timing accurate (~${death_time}ms)${RESET}"
	else
		echo -e "${YELLOW}⚠️  Death occurred at ${death_time}ms (slightly off)${RESET}"
	fi
fi

echo -e "\n${GREEN}🎉 All tests completed.${RESET}"
