/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ gzip / gzip /
  tb
  s/ $/ gzip /
  :b
  s/^/# Packages using this file:/
}
