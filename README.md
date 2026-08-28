# Computer Programming I (컴퓨터프로그래밍 I)

Lab manual and lecture slides for Computer Programming I, 400521-004,
Dong-eui University, Dept. of Intelligent Computing. Deployed via
GitHub Pages, see `.github/workflows/deploy.yml`.

Read `SPINE.md` first: it defines the pedagogical structure every
lecture deck follows (motivation before definition, weeks chained via
a Limits-to-Pain handoff). `OUTLINE.md` has the full 15-week plan and
chain table.

## Layout

```
SPINE.md                  standard lecture structure, read this first
OUTLINE.md                15-week plan + Limits-to-Pain chain
themes/shintia.css         Marp theme, shared with the sibling courses
assets/deu-logo.png         university logo
book/                      mdBook lab manual - full guided labs, rubrics
  book.toml
  src/
    introduction.md
    labs/                   lab01 ... lab15 (one per week)
    setup/                  toolchain + how a program runs
    appendix/                style guide, rubrics, debugging tips, references
      bonus/                 optional enrichment (bitwise, file I/O, malloc)
slides/
  _template/week-XX.md      copy this to start a new week deck
  _shared/roadmap.md        Act-0 roadmap graphic, paste into slot 2
  week01-introduction.md ... week15-final-exam.md   17-slot lecture decks
landing/index.html          site root - links the book and every deck
solutions/                  instructor answer keys (problems.md is public, answer-key/ is not built/published)
docs/                        syllabus (silabus.md/.pdf/.jpg)
```

## Setup

Requires Node.js. First run installs marp-cli into `node_modules` via
`npx`. No separate `npm install` step needed.

```bash
npx @marp-team/marp-cli --version   # confirms marp-cli resolves
```

## Preview slides in a browser (live reload)

```bash
npx @marp-team/marp-cli -s slides --theme-set themes/shintia.css
```

## Zero-install alternative: VS Code

Install the **Marp for VS Code** extension, open any `slides/*.md`
file, and use the built-in preview pane. To pick up the custom theme,
add to VS Code settings:

```json
"markdown.marp.themes": ["./themes/shintia.css"]
```

## Build the book

```bash
mdbook build book   # -> book/book/, open book/book/index.html
```

## Release the book as per-chapter PDFs

```bash
npm run build:book-pdfs   # -> book/pdf/*.pdf, one per SUMMARY.md chapter, + book/pdf/index.html
```

Renders each already-built chapter page to its own PDF via headless
Chrome/Chromium (`scripts/build-book-pdfs.js`). Needs a
`google-chrome` or `chromium` binary on PATH (or `$CHROME_PATH`) —
GitHub Actions' `ubuntu-latest` runners ship Chrome preinstalled, so
CI needs no extra install step. Wired into
`.github/workflows/deploy.yml`, published at `/book/pdf/` on the live
site. This replaces the old `docs/build-book.sh` single-file PDF
script — that mechanism and its committed `docs/lab-manual.pdf` have
been retired.

## Build the slides

```bash
npm run build:html   # -> dist/slides/*.html, self-contained
npm run build:pdf     # -> dist/slides/*.pdf
npm run build:pptx    # -> dist/slides/*.pptx
```

## Adding a new week deck

1. Copy `slides/_template/week-XX.md` to `slides/weekNN-topic.md`,
   fill in all 17 spine slots (see `SPINE.md`).
2. Paste the roadmap `<div>` from `slides/_shared/roadmap.md` into
   slot 2, mark the new current week's `.wk` div `class="wk now"`.
3. Preview, check against `SPINE.md`'s hard rule: no formal
   definition before slot 8.
4. Add the deck to `landing/index.html`'s deck list and to
   `OUTLINE.md`.

## Status

All 15 lecture decks (Weeks 1-15) are drafted, built, and themed with
`shintia.css` (the same theme as the sibling courses — same
instructor/department). Slides teach each week's matching lab's Part
A lecture content; the book covers the full guided exercises,
challenge problems, and submission rubrics. Instructor answer keys
for the labs' exercises live in `solutions/`, split from the public
problem statements — see `solutions/README.md`.
