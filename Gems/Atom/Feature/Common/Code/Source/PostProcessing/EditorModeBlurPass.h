/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <PostProcessing/EditorModeFeedbackPassBase.h>

namespace AZ
{
    namespace Render
    {
        //! Pass for editor mode feedback blur effect.
        class EditorModeBlurPass
            : public EditorModeFeedbackPassBase
        {
        public:
            AZ_RTTI(EditorModeBlurPass, "{D907D0ED-61E4-4E46-A682-A849676CF48A}", EditorModeFeedbackPassBase);
            AZ_CLASS_ALLOCATOR(EditorModeBlurPass, SystemAllocator, 0);

            virtual ~EditorModeBlurPass() = default;

            //! Creates a EditorModeBlurPass
            static RPI::Ptr<EditorModeBlurPass> Create(const RPI::PassDescriptor& descriptor);

            //! Sets the width of kernal to apply box blur effect.
            void SetKernalWidth(float width);

        protected:
            EditorModeBlurPass(const RPI::PassDescriptor& descriptor);
            
            //! Pass behavior overrides
            void InitializeInternal() override;
            void FrameBeginInternal(FramePrepareParams params) override;

        private:
            //! Sets the shader constant values for the blur effect.
            void SetSrgConstants();

            RHI::ShaderInputNameIndex m_kernalWidthIndex = "m_kernalWidth";
            float m_kernalWidth = 5.0f; //!< Default kernal width for the blur effect.
        };
    }   // namespace Render
}   // namespace AZ
