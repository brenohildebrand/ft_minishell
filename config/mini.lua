-- Hey there
-- This is the configuration file for mini

-- Constansts
local PRIMARY_COLOR = {r = 163, g = 190, b = 140}
local SECONDARY_COLOR = {r = 94, g = 129, b = 172}

-- Utilities
local function string_to_primary_color(string)
	return string.format("\x1b[38;2;%d;%d;%dm%s\x1b[0m", PRIMARY_COLOR.r, PRIMARY_COLOR.g, PRIMARY_COLOR.b, string)
end

local function string_to_secondary_color(string)
	return string.format("\x1b[38;2;%d;%d;%dm%s\x1b[0m", SECONDARY_COLOR.r, SECONDARY_COLOR.g, SECONDARY_COLOR.b, string)
end

local function string_to_bold(string)
	return string.format("\x1b[1m%s\x1b[0m", string);
end

-- Custom message for minishell initialization
local custom_message = "\027[91mLua is enabled.\027[0m\n"
print(custom_message);

-- Prompt
user = string_to_bold(string_to_primary_color(os.getenv("USER")))
name = string_to_bold(string_to_primary_color(os.getenv("NAME") or os.getenv("HOSTNAME")))
pwd = string_to_bold(string_to_secondary_color(os.getenv("PWD"):match("[\\/]?([^\\/]+)$")))
prompt = user .. string_to_bold(string_to_primary_color("@")) .. name .. ":" .. pwd .. "$ " 
