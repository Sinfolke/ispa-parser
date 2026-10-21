"""Run with python3 tests/bridge_test.py path/to/ispa-grammar-bridge."""
import json
import subprocess
import sys
import unittest

BINARY = sys.argv.pop(1)


class BridgeTests(unittest.TestCase):
    def parse(self, source):
        process = subprocess.run([BINARY], input=source, text=True, capture_output=True, timeout=5)
        self.assertEqual(process.returncode, 0, process.stderr[-1000:])
        result = json.loads(process.stdout)
        for item in result['tokens'] + result['diagnostics']:
            self.assertLessEqual(item['start'] + item['length'], len(source.encode()))
        return result

    def test_semantic_declaration(self):
        result = self.parse("entry: 'x';")
        self.assertTrue(result['ok'])
        self.assertTrue(any(t['role'] == 'declaration' for t in result['tokens']))

    def test_module_preprocessing(self):
        result = self.parse("module main; import { ID } from common; feature cpp_constexpr { ID }; detach feature cpp_constexpr; entry: ID?;")
        self.assertTrue(result['ok'], result['diagnostics'])

    def test_dotted_module_paths(self):
        for directive in (
            "module rule.regular;",
            "module rule.regular -> regular_rule;",
            "module rule . regular -> outer -> inner;",
            "import rule.regular;",
            "import rule.regular as regular;",
            "import { outer->inner, ID } from rule.regular;",
            "import * from rule.regular;",
        ):
            with self.subTest(directive=directive):
                result = self.parse(directive + " entry: 'x';")
                self.assertTrue(result['ok'], result['diagnostics'])

    def test_invalid_module_paths(self):
        for directive in (
            "module .regular;",
            "module rule.;",
            "module rule..regular;",
            "module rule.regular ->;",
            "module rule.regular -> outer.inner;",
            "import rule->regular;",
            "import * from rule..regular;",
        ):
            with self.subTest(directive=directive):
                result = self.parse(directive + " entry: 'x';")
                self.assertFalse(result['ok'])
                self.assertIn('Invalid ' + directive.split()[0], result['diagnostics'][0]['message'])

    def test_expected_semicolon_at_eof(self):
        source = "// 😀\nentry: 'x'"
        result = self.parse(source)
        self.assertFalse(result['ok'])
        self.assertTrue(result['tokens'])
        self.assertEqual(result['diagnostics'][0]['start'], len(source.encode()))
        self.assertIn('SEMICOLON', result['diagnostics'][0]['message'])

    def test_trailing_incomplete_rule(self):
        source = "entry: 'x';\nwrong"
        result = self.parse(source)
        self.assertFalse(result['ok'])
        self.assertEqual(result['diagnostics'][0]['start'], source.index('wrong'))

    def test_lexical_failure_keeps_prefix(self):
        result = self.parse("entry: 'unfinished")
        self.assertFalse(result['ok'])
        self.assertTrue(result['tokens'])
        self.assertEqual(result['diagnostics'][0]['start'], 7)

    def test_invalid_directive(self):
        result = self.parse("import { } from; entry: 'x';")
        self.assertFalse(result['ok'])
        self.assertIn('Invalid import', result['diagnostics'][0]['message'])

    def test_block_comments(self):
        self.assertTrue(self.parse("/* comment */ entry: [a-z]+; // final")['ok'])
        self.assertFalse(self.parse("entry: 'x'; /* unfinished")['ok'])


if __name__ == '__main__':
    unittest.main()
