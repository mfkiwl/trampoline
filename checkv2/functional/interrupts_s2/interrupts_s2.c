/**
 * @file interrupts_s2/interrupts_s2.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "embUnit.h"

TestRef InterruptProcessingTest_seq2_t1_instance(void);
TestRef InterruptProcessingTest_seq2_t2_instance(void);
TestRef InterruptProcessingTest_seq2_isr1_instance(void);
TestRef InterruptProcessingTest_seq2_isr2_instance(void);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(InterruptProcessingTest_seq2_t1_instance());
}

TASK(t2)
{
	TestRunner_runTest(InterruptProcessingTest_seq2_t2_instance());
	ShutdownOS(E_OK);
}

ISR(isr1)
{
	TestRunner_runTest(InterruptProcessingTest_seq2_isr1_instance());
}

ISR(isr2)
{
	TestRunner_runTest(InterruptProcessingTest_seq2_isr2_instance());
}

/* End of file interrupts_s2/interrupts_s2.c */