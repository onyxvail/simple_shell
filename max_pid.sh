#!/bin/bash
echo "Maximum process ID: $(grep -oP '^#define PID_MAX \K.*'/usr/include/linux/limits.h)"

