# Computer Programming I — Lab Manual

Course: **400521-004 컴퓨터프로그래밍 I** · Instructor: Yushintia Pramitarini · 2025

## Build

```bash
# Web only
mdbook build          # output → book/

# Web + PDF (one command)
bash docs/build-book.sh

# Live preview (hot-reload)
mdbook serve --open
```

## Outputs

| Format | Path | Description |
|--------|------|-------------|
| Web    | `book/index.html` | Browsable static site with search sidebar |
| PDF    | `docs/lab-manual.pdf` | A4 print version (all 15 labs + appendices) |
| Syllabus | `docs/silabus.pdf` | Korean/English LMS syllabus form |

## Structure

```
src/
├── introduction.md       Course overview, objectives, grading
├── setup/                Toolchain setup + how a program runs
├── labs/                 lab01 … lab15 (one per week)
└── appendix/             Style guide, rubrics, debugging tips, references
    └── bonus/            Optional enrichment (bitwise, file I/O, malloc)
```

## Requirements

- `mdbook` ≥ 0.5  (`cargo install mdbook`)
- Chromium (for PDF)  (`chromium --version`)
- Noto Sans KR font (for Korean in PDF; see `docs/build-book.sh`)
