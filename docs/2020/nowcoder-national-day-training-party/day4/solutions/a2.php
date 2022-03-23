<?php
$n = intval(fgets(STDIN));
$s0 = trim(fgets(STDIN));
for ($i = 0; $i < $n; $i++) {
$s = trim(fgets(STDIN));

if (strnatcmp($s0, $s) > 0) {
$result = '-';
} else {
$result = '+';
}

echo "$result\n";
}